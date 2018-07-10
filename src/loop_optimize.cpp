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
    const int data_points = SIMDPP_FAST_FLOAT32_SIZE;

    for (size_t i = 0; i < size; i += data_points)
    {
        simdpp::float32<data_points> arr1_simdvec = simdpp::load(arr1 + i);
        simdpp::float32<data_points> arr2_simdvec = simdpp::load(arr2 + i);
        simdpp::float32<data_points> diff = simdpp::sub(arr1_simdvec, arr2_simdvec);
        simdpp::float32<data_points> squares = simdpp::mul(diff, diff);
        result += simdpp::reduce_add(squares);
    }

    return result;
}

} //end namespace simd_optimizations