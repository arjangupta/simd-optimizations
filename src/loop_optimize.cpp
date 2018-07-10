#include "loop_optimize.h"

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
        return 0.0;
    }

} //end namespace simd_optimizations