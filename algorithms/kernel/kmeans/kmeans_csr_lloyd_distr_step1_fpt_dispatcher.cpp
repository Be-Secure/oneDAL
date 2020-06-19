/* file: kmeans_csr_lloyd_distr_step1_fpt_dispatcher.cpp */
/*******************************************************************************
* Copyright 2014-2020 Intel Corporation
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
//++
//  Implementation of K-means algorithm container -- a class that contains
//  Lloyd K-means kernels for supported architectures.
//--
*/

#include "algorithms/kernel/kmeans/kmeans_container.h"

namespace daal
{
namespace algorithms
{
__DAAL_INSTANTIATE_DISPATCH_CONTAINER(kmeans::interface2::DistributedContainer, distributed, step1Local, DAAL_FPTYPE, kmeans::lloydCSR)

namespace kmeans
{
namespace interface2
{
using DistributedType = Distributed<step1Local, DAAL_FPTYPE, kmeans::lloydCSR>;

template <>
DistributedType::Distributed(size_t nClusters, bool assignFlag)
{
    _par = new ParameterType(nClusters, 1);
    initialize();
    if (!assignFlag)
    {
        parameter().resultsToEvaluate &= ~computeAssignments;
    }
}

template <>
DistributedType::Distributed(const DistributedType & other)
{
    _par = new ParameterType(other.parameter());
    initialize();
    input.set(data, other.input.get(data));
    input.set(inputCentroids, other.input.get(inputCentroids));
}

} // namespace interface2
} // namespace kmeans

} // namespace algorithms
} // namespace daal
