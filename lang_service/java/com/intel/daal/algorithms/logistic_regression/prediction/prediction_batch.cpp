/* file: prediction_batch.cpp */
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

#include "daal.h"
#include "com_intel_daal_algorithms_logistic_regression_prediction_PredictionBatch.h"

#include "lang_service/java/com/intel/daal/include/common_helpers.h"

USING_COMMON_NAMESPACES()
using namespace daal::algorithms::logistic_regression::prediction;

/*
 * Class:     com_intel_daal_algorithms_logistic_regression_prediction_PredictionBatch
 * Method:    cInit
 * Signature:(IIJ)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_logistic_1regression_prediction_PredictionBatch_cInit(JNIEnv * env, jobject thisObj, jint prec,
                                                                                                             jint method, jlong nClasses)
{
    return jniBatch<logistic_regression::prediction::Method, Batch, defaultDense>::newObj(prec, method, nClasses);
}

/*
 * Class:     com_intel_daal_algorithms_logistic_regression_prediction_PredictionBatch
 * Method:    cInitParameter
 * Signature:(JIII)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_logistic_1regression_prediction_PredictionBatch_cInitParameter(JNIEnv * env, jobject thisObj,
                                                                                                                      jlong algAddr, jint prec,
                                                                                                                      jint method)
{
    return jniBatch<logistic_regression::prediction::Method, Batch, defaultDense>::getParameter(prec, method, algAddr);
}

/*
 * Class:     com_intel_daal_algorithms_logistic_regression_prediction_PredictionBatch
 * Method:    cClone
 * Signature:(JII)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_logistic_1regression_prediction_PredictionBatch_cClone(JNIEnv * env, jobject thisObj,
                                                                                                              jlong algAddr, jint prec, jint method)
{
    return jniBatch<logistic_regression::prediction::Method, Batch, defaultDense>::getClone(prec, method, algAddr);
}

/*
 * Class:     com_intel_daal_algorithms_logistic_regression_prediction_PredictionBatch
 * Method:    cGetResult
 * Signature:(JII)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_logistic_1regression_prediction_PredictionBatch_cGetResult(JNIEnv * env, jobject thisObj,
                                                                                                                  jlong algAddr, jint prec,
                                                                                                                  jint method)
{
    return jniBatch<logistic_regression::prediction::Method, Batch, defaultDense>::getResult(prec, method, algAddr);
}

/*
 * Class:     com_intel_daal_algorithms_logistic_regression_prediction_PredictionBatch
 * Method:    cSetResult
 * Signature:(JIIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_logistic_1regression_prediction_PredictionBatch_cSetResult(JNIEnv * env, jobject thisObj,
                                                                                                                 jlong algAddr, jint prec,
                                                                                                                 jint method, jlong resultAddr)
{
    jniBatch<logistic_regression::prediction::Method, Batch, defaultDense>::setResult<classifier::prediction::Result>(prec, method, algAddr,
                                                                                                                      resultAddr);
}
