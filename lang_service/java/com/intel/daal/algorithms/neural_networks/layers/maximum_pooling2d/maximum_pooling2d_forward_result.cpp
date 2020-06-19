/* file: maximum_pooling2d_forward_result.cpp */
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

#include <jni.h>
#include "com_intel_daal_algorithms_neural_networks_layers_maximum_pooling2d_MaximumPooling2dForwardResult.h"

#include "daal.h"

#include "lang_service/java/com/intel/daal/include/common_helpers.h"

#include "com_intel_daal_algorithms_neural_networks_layers_maximum_pooling2d_MaximumPooling2dLayerDataId.h"
#define auxSelectedIndicesId com_intel_daal_algorithms_neural_networks_layers_maximum_pooling2d_MaximumPooling2dLayerDataId_auxSelectedIndicesId
#include "com_intel_daal_algorithms_neural_networks_layers_maximum_pooling2d_MaximumPooling2dLayerDataNumericTableId.h"
#define auxInputDimensionsId \
    com_intel_daal_algorithms_neural_networks_layers_maximum_pooling2d_MaximumPooling2dLayerDataNumericTableId_auxInputDimensionsId

USING_COMMON_NAMESPACES();
using namespace daal::algorithms::neural_networks::layers::maximum_pooling2d;

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_maximum_1pooling2d_MaximumPooling2dForwardResult
 * Method:    cNewResult
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
    Java_com_intel_daal_algorithms_neural_1networks_layers_maximum_1pooling2d_MaximumPooling2dForwardResult_cNewResult(JNIEnv * env, jobject thisObj)
{
    return jniArgument<forward::Result>::newObj();
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_maximum_1pooling2d_MaximumPooling2dForwardResult
 * Method:    cGetValue
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_maximum_1pooling2d_MaximumPooling2dForwardResult_cGetValue(
    JNIEnv * env, jobject thisObj, jlong resAddr, jint id)
{
    if (id == auxSelectedIndicesId)
    {
        return jniArgument<forward::Result>::get<LayerDataId, Tensor>(resAddr, id);
    }

    return (jlong)0;
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_maximum_1pooling2d_MaximumPooling2dForwardResult
 * Method:    cSetValue
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_maximum_1pooling2d_MaximumPooling2dForwardResult_cSetValue(
    JNIEnv * env, jobject thisObj, jlong resAddr, jint id, jlong ntAddr)
{
    if (id == auxSelectedIndicesId)
    {
        jniArgument<forward::Result>::set<LayerDataId, Tensor>(resAddr, auxSelectedIndices, id);
    }
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_maximum_pooling2d_MaximumPooling2dForwardResult
 * Method:    cGetNumericTableValue
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_maximum_1pooling2d_MaximumPooling2dForwardResult_cGetNumericTableValue(
    JNIEnv * env, jobject thisObj, jlong resAddr, jint id)
{
    if (id == auxInputDimensionsId)
    {
        return jniArgument<forward::Result>::get<LayerDataNumericTableId, NumericTable>(resAddr, id);
    }

    return (jlong)0;
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_maximum_pooling2d_MaximumPooling2dForwardResult
 * Method:    cSetNumericTableValue
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_maximum_1pooling2d_MaximumPooling2dForwardResult_cSetNumericTableValue(
    JNIEnv * env, jobject thisObj, jlong resAddr, jint id, jlong ntAddr)
{
    if (id == auxInputDimensionsId)
    {
        jniArgument<forward::Result>::set<LayerDataNumericTableId, NumericTable>(resAddr, auxInputDimensions, id);
    }
}
