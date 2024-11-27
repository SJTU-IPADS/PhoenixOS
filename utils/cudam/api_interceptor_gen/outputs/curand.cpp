/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <curand.h>

#include "cudam.h"
#include "api_counter.h"

#undef curandCreateGenerator
curandStatus_t curandCreateGenerator(curandGenerator_t * generator, curandRngType_t rng_type){
    curandStatus_t lretval;
    curandStatus_t (*lcurandCreateGenerator) (curandGenerator_t *, curandRngType_t) = (curandStatus_t (*)(curandGenerator_t *, curandRngType_t))dlsym(RTLD_NEXT, "curandCreateGenerator");
    
    /* pre exeuction logics */
    ac.add_counter("curandCreateGenerator", kApiTypeCuRand);

    lretval = lcurandCreateGenerator(generator, rng_type);
    
    /* post exeuction logics */

    return lretval;
}
#define curandCreateGenerator curandCreateGenerator


#undef curandCreateGeneratorHost
curandStatus_t curandCreateGeneratorHost(curandGenerator_t * generator, curandRngType_t rng_type){
    curandStatus_t lretval;
    curandStatus_t (*lcurandCreateGeneratorHost) (curandGenerator_t *, curandRngType_t) = (curandStatus_t (*)(curandGenerator_t *, curandRngType_t))dlsym(RTLD_NEXT, "curandCreateGeneratorHost");
    
    /* pre exeuction logics */
    ac.add_counter("curandCreateGeneratorHost", kApiTypeCuRand);

    lretval = lcurandCreateGeneratorHost(generator, rng_type);
    
    /* post exeuction logics */

    return lretval;
}
#define curandCreateGeneratorHost curandCreateGeneratorHost


#undef curandDestroyGenerator
curandStatus_t curandDestroyGenerator(curandGenerator_t generator){
    curandStatus_t lretval;
    curandStatus_t (*lcurandDestroyGenerator) (curandGenerator_t) = (curandStatus_t (*)(curandGenerator_t))dlsym(RTLD_NEXT, "curandDestroyGenerator");
    
    /* pre exeuction logics */
    ac.add_counter("curandDestroyGenerator", kApiTypeCuRand);

    lretval = lcurandDestroyGenerator(generator);
    
    /* post exeuction logics */

    return lretval;
}
#define curandDestroyGenerator curandDestroyGenerator


#undef curandGetVersion
curandStatus_t curandGetVersion(int * version){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGetVersion) (int *) = (curandStatus_t (*)(int *))dlsym(RTLD_NEXT, "curandGetVersion");
    
    /* pre exeuction logics */
    ac.add_counter("curandGetVersion", kApiTypeCuRand);

    lretval = lcurandGetVersion(version);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGetVersion curandGetVersion


#undef curandGetProperty
curandStatus_t curandGetProperty(libraryPropertyType type, int * value){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGetProperty) (libraryPropertyType, int *) = (curandStatus_t (*)(libraryPropertyType, int *))dlsym(RTLD_NEXT, "curandGetProperty");
    
    /* pre exeuction logics */
    ac.add_counter("curandGetProperty", kApiTypeCuRand);

    lretval = lcurandGetProperty(type, value);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGetProperty curandGetProperty


#undef curandSetStream
curandStatus_t curandSetStream(curandGenerator_t generator, cudaStream_t stream){
    curandStatus_t lretval;
    curandStatus_t (*lcurandSetStream) (curandGenerator_t, cudaStream_t) = (curandStatus_t (*)(curandGenerator_t, cudaStream_t))dlsym(RTLD_NEXT, "curandSetStream");
    
    /* pre exeuction logics */
    ac.add_counter("curandSetStream", kApiTypeCuRand);

    lretval = lcurandSetStream(generator, stream);
    
    /* post exeuction logics */

    return lretval;
}
#define curandSetStream curandSetStream


#undef curandSetPseudoRandomGeneratorSeed
curandStatus_t curandSetPseudoRandomGeneratorSeed(curandGenerator_t generator, long long unsigned int seed){
    curandStatus_t lretval;
    curandStatus_t (*lcurandSetPseudoRandomGeneratorSeed) (curandGenerator_t, long long unsigned int) = (curandStatus_t (*)(curandGenerator_t, long long unsigned int))dlsym(RTLD_NEXT, "curandSetPseudoRandomGeneratorSeed");
    
    /* pre exeuction logics */
    ac.add_counter("curandSetPseudoRandomGeneratorSeed", kApiTypeCuRand);

    lretval = lcurandSetPseudoRandomGeneratorSeed(generator, seed);
    
    /* post exeuction logics */

    return lretval;
}
#define curandSetPseudoRandomGeneratorSeed curandSetPseudoRandomGeneratorSeed


#undef curandSetGeneratorOffset
curandStatus_t curandSetGeneratorOffset(curandGenerator_t generator, long long unsigned int offset){
    curandStatus_t lretval;
    curandStatus_t (*lcurandSetGeneratorOffset) (curandGenerator_t, long long unsigned int) = (curandStatus_t (*)(curandGenerator_t, long long unsigned int))dlsym(RTLD_NEXT, "curandSetGeneratorOffset");
    
    /* pre exeuction logics */
    ac.add_counter("curandSetGeneratorOffset", kApiTypeCuRand);

    lretval = lcurandSetGeneratorOffset(generator, offset);
    
    /* post exeuction logics */

    return lretval;
}
#define curandSetGeneratorOffset curandSetGeneratorOffset


#undef curandSetGeneratorOrdering
curandStatus_t curandSetGeneratorOrdering(curandGenerator_t generator, curandOrdering_t order){
    curandStatus_t lretval;
    curandStatus_t (*lcurandSetGeneratorOrdering) (curandGenerator_t, curandOrdering_t) = (curandStatus_t (*)(curandGenerator_t, curandOrdering_t))dlsym(RTLD_NEXT, "curandSetGeneratorOrdering");
    
    /* pre exeuction logics */
    ac.add_counter("curandSetGeneratorOrdering", kApiTypeCuRand);

    lretval = lcurandSetGeneratorOrdering(generator, order);
    
    /* post exeuction logics */

    return lretval;
}
#define curandSetGeneratorOrdering curandSetGeneratorOrdering


#undef curandSetQuasiRandomGeneratorDimensions
curandStatus_t curandSetQuasiRandomGeneratorDimensions(curandGenerator_t generator, unsigned int num_dimensions){
    curandStatus_t lretval;
    curandStatus_t (*lcurandSetQuasiRandomGeneratorDimensions) (curandGenerator_t, unsigned int) = (curandStatus_t (*)(curandGenerator_t, unsigned int))dlsym(RTLD_NEXT, "curandSetQuasiRandomGeneratorDimensions");
    
    /* pre exeuction logics */
    ac.add_counter("curandSetQuasiRandomGeneratorDimensions", kApiTypeCuRand);

    lretval = lcurandSetQuasiRandomGeneratorDimensions(generator, num_dimensions);
    
    /* post exeuction logics */

    return lretval;
}
#define curandSetQuasiRandomGeneratorDimensions curandSetQuasiRandomGeneratorDimensions


#undef curandGenerate
curandStatus_t curandGenerate(curandGenerator_t generator, unsigned int * outputPtr, size_t num){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerate) (curandGenerator_t, unsigned int *, size_t) = (curandStatus_t (*)(curandGenerator_t, unsigned int *, size_t))dlsym(RTLD_NEXT, "curandGenerate");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerate", kApiTypeCuRand);

    lretval = lcurandGenerate(generator, outputPtr, num);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerate curandGenerate


#undef curandGenerateLongLong
curandStatus_t curandGenerateLongLong(curandGenerator_t generator, long long unsigned int * outputPtr, size_t num){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateLongLong) (curandGenerator_t, long long unsigned int *, size_t) = (curandStatus_t (*)(curandGenerator_t, long long unsigned int *, size_t))dlsym(RTLD_NEXT, "curandGenerateLongLong");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateLongLong", kApiTypeCuRand);

    lretval = lcurandGenerateLongLong(generator, outputPtr, num);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateLongLong curandGenerateLongLong


#undef curandGenerateUniform
curandStatus_t curandGenerateUniform(curandGenerator_t generator, float * outputPtr, size_t num){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateUniform) (curandGenerator_t, float *, size_t) = (curandStatus_t (*)(curandGenerator_t, float *, size_t))dlsym(RTLD_NEXT, "curandGenerateUniform");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateUniform", kApiTypeCuRand);

    lretval = lcurandGenerateUniform(generator, outputPtr, num);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateUniform curandGenerateUniform


#undef curandGenerateUniformDouble
curandStatus_t curandGenerateUniformDouble(curandGenerator_t generator, double * outputPtr, size_t num){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateUniformDouble) (curandGenerator_t, double *, size_t) = (curandStatus_t (*)(curandGenerator_t, double *, size_t))dlsym(RTLD_NEXT, "curandGenerateUniformDouble");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateUniformDouble", kApiTypeCuRand);

    lretval = lcurandGenerateUniformDouble(generator, outputPtr, num);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateUniformDouble curandGenerateUniformDouble


#undef curandGenerateNormal
curandStatus_t curandGenerateNormal(curandGenerator_t generator, float * outputPtr, size_t n, float mean, float stddev){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateNormal) (curandGenerator_t, float *, size_t, float, float) = (curandStatus_t (*)(curandGenerator_t, float *, size_t, float, float))dlsym(RTLD_NEXT, "curandGenerateNormal");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateNormal", kApiTypeCuRand);

    lretval = lcurandGenerateNormal(generator, outputPtr, n, mean, stddev);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateNormal curandGenerateNormal


#undef curandGenerateNormalDouble
curandStatus_t curandGenerateNormalDouble(curandGenerator_t generator, double * outputPtr, size_t n, double mean, double stddev){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateNormalDouble) (curandGenerator_t, double *, size_t, double, double) = (curandStatus_t (*)(curandGenerator_t, double *, size_t, double, double))dlsym(RTLD_NEXT, "curandGenerateNormalDouble");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateNormalDouble", kApiTypeCuRand);

    lretval = lcurandGenerateNormalDouble(generator, outputPtr, n, mean, stddev);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateNormalDouble curandGenerateNormalDouble


#undef curandGenerateLogNormal
curandStatus_t curandGenerateLogNormal(curandGenerator_t generator, float * outputPtr, size_t n, float mean, float stddev){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateLogNormal) (curandGenerator_t, float *, size_t, float, float) = (curandStatus_t (*)(curandGenerator_t, float *, size_t, float, float))dlsym(RTLD_NEXT, "curandGenerateLogNormal");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateLogNormal", kApiTypeCuRand);

    lretval = lcurandGenerateLogNormal(generator, outputPtr, n, mean, stddev);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateLogNormal curandGenerateLogNormal


#undef curandGenerateLogNormalDouble
curandStatus_t curandGenerateLogNormalDouble(curandGenerator_t generator, double * outputPtr, size_t n, double mean, double stddev){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateLogNormalDouble) (curandGenerator_t, double *, size_t, double, double) = (curandStatus_t (*)(curandGenerator_t, double *, size_t, double, double))dlsym(RTLD_NEXT, "curandGenerateLogNormalDouble");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateLogNormalDouble", kApiTypeCuRand);

    lretval = lcurandGenerateLogNormalDouble(generator, outputPtr, n, mean, stddev);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateLogNormalDouble curandGenerateLogNormalDouble


#undef curandCreatePoissonDistribution
curandStatus_t curandCreatePoissonDistribution(double lambda, curandDiscreteDistribution_t * discrete_distribution){
    curandStatus_t lretval;
    curandStatus_t (*lcurandCreatePoissonDistribution) (double, curandDiscreteDistribution_t *) = (curandStatus_t (*)(double, curandDiscreteDistribution_t *))dlsym(RTLD_NEXT, "curandCreatePoissonDistribution");
    
    /* pre exeuction logics */
    ac.add_counter("curandCreatePoissonDistribution", kApiTypeCuRand);

    lretval = lcurandCreatePoissonDistribution(lambda, discrete_distribution);
    
    /* post exeuction logics */

    return lretval;
}
#define curandCreatePoissonDistribution curandCreatePoissonDistribution


#undef curandDestroyDistribution
curandStatus_t curandDestroyDistribution(curandDiscreteDistribution_t discrete_distribution){
    curandStatus_t lretval;
    curandStatus_t (*lcurandDestroyDistribution) (curandDiscreteDistribution_t) = (curandStatus_t (*)(curandDiscreteDistribution_t))dlsym(RTLD_NEXT, "curandDestroyDistribution");
    
    /* pre exeuction logics */
    ac.add_counter("curandDestroyDistribution", kApiTypeCuRand);

    lretval = lcurandDestroyDistribution(discrete_distribution);
    
    /* post exeuction logics */

    return lretval;
}
#define curandDestroyDistribution curandDestroyDistribution


#undef curandGeneratePoisson
curandStatus_t curandGeneratePoisson(curandGenerator_t generator, unsigned int * outputPtr, size_t n, double lambda){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGeneratePoisson) (curandGenerator_t, unsigned int *, size_t, double) = (curandStatus_t (*)(curandGenerator_t, unsigned int *, size_t, double))dlsym(RTLD_NEXT, "curandGeneratePoisson");
    
    /* pre exeuction logics */
    ac.add_counter("curandGeneratePoisson", kApiTypeCuRand);

    lretval = lcurandGeneratePoisson(generator, outputPtr, n, lambda);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGeneratePoisson curandGeneratePoisson


#undef curandGeneratePoissonMethod
curandStatus_t curandGeneratePoissonMethod(curandGenerator_t generator, unsigned int * outputPtr, size_t n, double lambda, curandMethod_t method){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGeneratePoissonMethod) (curandGenerator_t, unsigned int *, size_t, double, curandMethod_t) = (curandStatus_t (*)(curandGenerator_t, unsigned int *, size_t, double, curandMethod_t))dlsym(RTLD_NEXT, "curandGeneratePoissonMethod");
    
    /* pre exeuction logics */
    ac.add_counter("curandGeneratePoissonMethod", kApiTypeCuRand);

    lretval = lcurandGeneratePoissonMethod(generator, outputPtr, n, lambda, method);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGeneratePoissonMethod curandGeneratePoissonMethod


#undef curandGenerateBinomial
curandStatus_t curandGenerateBinomial(curandGenerator_t generator, unsigned int * outputPtr, size_t num, unsigned int n, double p){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateBinomial) (curandGenerator_t, unsigned int *, size_t, unsigned int, double) = (curandStatus_t (*)(curandGenerator_t, unsigned int *, size_t, unsigned int, double))dlsym(RTLD_NEXT, "curandGenerateBinomial");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateBinomial", kApiTypeCuRand);

    lretval = lcurandGenerateBinomial(generator, outputPtr, num, n, p);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateBinomial curandGenerateBinomial


#undef curandGenerateBinomialMethod
curandStatus_t curandGenerateBinomialMethod(curandGenerator_t generator, unsigned int * outputPtr, size_t num, unsigned int n, double p, curandMethod_t method){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateBinomialMethod) (curandGenerator_t, unsigned int *, size_t, unsigned int, double, curandMethod_t) = (curandStatus_t (*)(curandGenerator_t, unsigned int *, size_t, unsigned int, double, curandMethod_t))dlsym(RTLD_NEXT, "curandGenerateBinomialMethod");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateBinomialMethod", kApiTypeCuRand);

    lretval = lcurandGenerateBinomialMethod(generator, outputPtr, num, n, p, method);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateBinomialMethod curandGenerateBinomialMethod


#undef curandGenerateSeeds
curandStatus_t curandGenerateSeeds(curandGenerator_t generator){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGenerateSeeds) (curandGenerator_t) = (curandStatus_t (*)(curandGenerator_t))dlsym(RTLD_NEXT, "curandGenerateSeeds");
    
    /* pre exeuction logics */
    ac.add_counter("curandGenerateSeeds", kApiTypeCuRand);

    lretval = lcurandGenerateSeeds(generator);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGenerateSeeds curandGenerateSeeds


#undef curandGetDirectionVectors32
curandStatus_t curandGetDirectionVectors32(curandDirectionVectors32_t * * vectors, curandDirectionVectorSet_t set){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGetDirectionVectors32) (curandDirectionVectors32_t * *, curandDirectionVectorSet_t) = (curandStatus_t (*)(curandDirectionVectors32_t * *, curandDirectionVectorSet_t))dlsym(RTLD_NEXT, "curandGetDirectionVectors32");
    
    /* pre exeuction logics */
    ac.add_counter("curandGetDirectionVectors32", kApiTypeCuRand);

    lretval = lcurandGetDirectionVectors32(vectors, set);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGetDirectionVectors32 curandGetDirectionVectors32


#undef curandGetScrambleConstants32
curandStatus_t curandGetScrambleConstants32(unsigned int * * constants){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGetScrambleConstants32) (unsigned int * *) = (curandStatus_t (*)(unsigned int * *))dlsym(RTLD_NEXT, "curandGetScrambleConstants32");
    
    /* pre exeuction logics */
    ac.add_counter("curandGetScrambleConstants32", kApiTypeCuRand);

    lretval = lcurandGetScrambleConstants32(constants);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGetScrambleConstants32 curandGetScrambleConstants32


#undef curandGetDirectionVectors64
curandStatus_t curandGetDirectionVectors64(curandDirectionVectors64_t * * vectors, curandDirectionVectorSet_t set){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGetDirectionVectors64) (curandDirectionVectors64_t * *, curandDirectionVectorSet_t) = (curandStatus_t (*)(curandDirectionVectors64_t * *, curandDirectionVectorSet_t))dlsym(RTLD_NEXT, "curandGetDirectionVectors64");
    
    /* pre exeuction logics */
    ac.add_counter("curandGetDirectionVectors64", kApiTypeCuRand);

    lretval = lcurandGetDirectionVectors64(vectors, set);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGetDirectionVectors64 curandGetDirectionVectors64


#undef curandGetScrambleConstants64
curandStatus_t curandGetScrambleConstants64(long long unsigned int * * constants){
    curandStatus_t lretval;
    curandStatus_t (*lcurandGetScrambleConstants64) (long long unsigned int * *) = (curandStatus_t (*)(long long unsigned int * *))dlsym(RTLD_NEXT, "curandGetScrambleConstants64");
    
    /* pre exeuction logics */
    ac.add_counter("curandGetScrambleConstants64", kApiTypeCuRand);

    lretval = lcurandGetScrambleConstants64(constants);
    
    /* post exeuction logics */

    return lretval;
}
#define curandGetScrambleConstants64 curandGetScrambleConstants64

