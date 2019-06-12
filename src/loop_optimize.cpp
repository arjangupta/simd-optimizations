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
    const int data_points = SIMDPP_FAST_FLOAT32_SIZE;

    simdpp::float32<data_points>* arr1_ptr = (simdpp::float32<data_points>*) arr1;
    simdpp::float32<data_points>* arr2_ptr = (simdpp::float32<data_points>*) arr2;

    size /= data_points;

    simdpp::float32<data_points> sum = simdpp::splat(0);

    for (size_t i = 0; i < size; ++i)
    {
        simdpp::float32<data_points> diff = arr1_ptr[i] - arr2_ptr[i];
        sum = sum + (diff * diff);
    }

    return simdpp::reduce_add(sum);
}

} //end namespace simd_optimizations