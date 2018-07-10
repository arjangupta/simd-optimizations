#include "loop_optimize.h"

#include <simdpp/simd.h>

namespace simd_optimizations
{

    float calculateNormalLoop(const float* arr1, const float* arr2, std::size_t size)
    {
        float result = 0;

        for (size_t i = 0; i < size; ++i)
        {
            float diff = arr1[i] - arr2[i];
            result += diff * diff;
        }

        return result;
    }

    float calculateOptimizedLoop(const float* arr1, const float* arr2, std::size_t size)
    {
        float result = 0;

        for (size_t i = 0; i < size; i += 4)
        {
            simdpp::float32<4> arr1_simdvec = simdpp::load(arr1 + i);
            simdpp::float32<4> arr2_simdvec = simdpp::load(arr2 + i);
            simdpp::float32<4> diff = simdpp::sub(arr1_simdvec, arr2_simdvec);
            simdpp::float32<4> squares = simdpp::mul(diff, diff);
            result += simdpp::reduce_add(squares);
        }

        return result;
    }

} //end namespace simd_optimizations