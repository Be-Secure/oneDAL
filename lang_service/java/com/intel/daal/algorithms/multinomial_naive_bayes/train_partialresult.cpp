/* file: train_partialresult.cpp */
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

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_intel_daal_algorithms_multinomial_naive_bayes_training_TrainingPartialResult */

#include "daal.h"
#include "com_intel_daal_algorithms_multinomial_naive_bayes_training_TrainingPartialResult.h"

#include "lang_service/java/com/intel/daal/include/common_helpers.h"

USING_COMMON_NAMESPACES();
using namespace daal::algorithms::multinomial_naive_bayes::training;

#include "com_intel_daal_algorithms_classifier_training_TrainingResultId.h"
#define ModelResult com_intel_daal_algorithms_classifier_training_TrainingResultId_Model

/*
 * Class:     com_intel_daal_algorithms_multinomial_naive_bayes_training_TrainingPartialResult
 * Method:    cNewPartialResult
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_multinomial_1naive_1bayes_training_TrainingPartialResult_cNewPartialResult(JNIEnv * env,
                                                                                                                                  jobject thisObj)
{
    return jniArgument<multinomial_naive_bayes::training::PartialResult>::newObj();
}

/*
 * Class:     com_intel_daal_algorithms_multinomial_naive_bayes_training_Batch_Result
 * Method:    cGetPartialModel
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_multinomial_1naive_1bayes_training_TrainingPartialResult_cGetPartialModel(JNIEnv * env,
                                                                                                                                 jobject thisObj,
                                                                                                                                 jlong resAddr,
                                                                                                                                 jint id)
{
    if (id == ModelResult)
    {
        return jniArgument<multinomial_naive_bayes::training::PartialResult>::get<classifier::training::PartialResultId,
                                                                                  multinomial_naive_bayes::PartialModel>(
            resAddr, classifier::training::partialModel);
    }

    return (jlong)0;
}
