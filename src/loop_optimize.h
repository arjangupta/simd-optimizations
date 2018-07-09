#ifndef LOOP_OPTIMIZE_H_
#define LOOP_OPTIMIZE_H_

namespace simd_optimizations
{
	float calculateNormalLoop(const float* arr1, const float* arr2, int size);
	float calculateOptimizedLoop(const float* arr1, const float* arr2, int size);
}

#endif //LOOP_OPTIMIZE_H_