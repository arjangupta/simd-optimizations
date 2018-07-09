#ifndef LOOP_OPTIMIZE_H_
#define LOOP_OPTIMIZE_H_

namespace simd_optimizations
{
	float calculateNormalLoop(const float* arr1, const float* arr2, size_t size);
	float calculateOptimizedLoop(const float* arr1, const float* arr2, size_t size);
}

#endif //LOOP_OPTIMIZE_H_