/* file: pca_cor_dense_batch.cpp */
/*******************************************************************************
* Copyright 2019 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
!  Content:
!    C++ example of principal component analysis (PCA) using the correlation
!    method in the batch processing mode with DPC++ interfaces
!
!******************************************************************************/

/**
 * <a name="DAAL-EXAMPLE-CPP-PCA_CORRELATION_DENSE_BATCH"></a>
 * \example pca_cor_dense_batch.cpp
 */

#include "daal_sycl.h"
#include "service.h"
#include "service_sycl.h"

using namespace daal;
using namespace daal::algorithms;

using daal::services::internal::SyclExecutionContext;
using daal::data_management::internal::SyclHomogenNumericTable;

/* Input data set parameters */
const std::string dataFileName = "../data/batch/pca_normalized.csv";

int main(int argc, char* argv[]) {
    checkArguments(argc, argv, 1, &dataFileName);

    for (const auto& deviceSelector : getListOfDevices()) {
        const auto& nameDevice = deviceSelector.first;
        const auto& device = deviceSelector.second;
        cl::sycl::queue queue(device);
        std::cout << "Running on " << nameDevice << "\n\n";

        SyclExecutionContext ctx(queue);
        services::Environment::getInstance()->setDefaultExecutionContext(ctx);

        /* Initialize FileDataSource<CSVFeatureManager> to retrieve the input data from a .csv file */
        FileDataSource<CSVFeatureManager> dataSource(dataFileName,
                                                     DataSource::notAllocateNumericTable,
                                                     DataSource::doDictionaryFromContext);

        auto data = SyclHomogenNumericTable<>::create(10, 0, NumericTable::notAllocate);
        /* Retrieve the data from the input file */
        dataSource.loadDataBlock(data.get());

        /* Create an algorithm for principal component analysis using the correlation method */
        pca::Batch<> algorithm;

        /* Set the algorithm input data */
        algorithm.input.set(pca::data, data);
        algorithm.parameter.resultsToCompute = pca::mean | pca::variance | pca::eigenvalue;
        algorithm.parameter.isDeterministic = true;

        /* Compute results of the PCA algorithm */
        algorithm.compute();

        /* Print the results */
        pca::ResultPtr result = algorithm.getResult();

        printNumericTable(result->get(pca::eigenvalues), "Eigenvalues:");
        printNumericTable(result->get(pca::eigenvectors), "Eigenvectors:");
        printNumericTable(result->get(pca::means), "Means:");
        printNumericTable(result->get(pca::variances), "Variances:");
    }

    return 0;
}
