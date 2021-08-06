/* file: ResultsToComputeId.java */
/*******************************************************************************
* Copyright 2020-2021 Intel Corporation
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

/**
 * @ingroup kmeans_compute
 * @{
 */
package com.intel.daal.algorithms.kmeans;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__KMEANS__RESULTTOCOMPUTEID"></a>
 * \brief Available identifiers of results of the KMEANS algorithm
 */
public final class ResultsToComputeId {
    public static final long computeCentroids              = 0x0000000000000001L; /*!< Compute table containing cluster centroids */
    public static final long computeExactObjectiveFunction = 0x0000000000000002L; /*!< Compute table containing exact objective function value */
    public static final long computeAssignments            = 0x0000000000000004L; /*!< Compute table containing assignments of observations to particular clustersons */
}/** @} */