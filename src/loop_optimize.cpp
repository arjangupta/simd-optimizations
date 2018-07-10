#include "loop_optimize.h"

#include <simdpp/simd.h>

namespace simd_optimizations
{

    float calculateNormalLoop(const float* arr1, const float* arr2, const std::size_t size)
    {
        float result = 0;

        for (size_t i = 0; i < size; ++i)
        {
            float diff = arr1[i] - arr2[i];
            result += diff * diff;
        }

        return result;
    }

    float calculateOptimizedLoop(const float* arr1, const float* arr2, const std::size_t size)
    {
        //Convert arrays to simd vectors
        simdpp::float32<size> arr1_simdvec = simdpp::load(arr1);
        simdpp::float32<size> arr2_simdvec = simdpp::load(arr2);
        
        //Algo
        simdpp::float32<size> diff    = simdpp::sub(arr1_simdvec, arr2_simdvec);
        simdpp::float32<size> squares = simdpp::mul(diff, diff);
        simdpp::float32<size> result  = simdpp::reduce_add(squares);

        float hello = 0.0;
        return hello;
    }

} //end namespace simd_optimizations