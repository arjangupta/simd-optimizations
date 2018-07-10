#include "loop_optimize.h"

#include <gtest/gtest.h>
#include <cmath>
#include <chrono>
#include <iostream>

using namespace simd_optimizations;

TEST(loopOptimizeUnitTest, timingTests)
{
	//Data
	size_t arr_size = 2960460;//296046 * 634
	float* arr1 = new float[arr_size];
	float* arr2 = new float[arr_size];

	for (size_t i = 0; i < arr_size; ++i)
	{
		//Arbitrarily chosen functions
		arr1[i] = sin(i);
		arr2[i] = tan(i);
	}

	//Timing vars
	std::chrono::steady_clock::time_point begin, end;

	//Time normal loop
	begin = std::chrono::steady_clock::now();
	float normal_loop_result = calculateNormalLoop(arr1, arr2, arr_size);
	end = std::chrono::steady_clock::now();

	std::chrono::microseconds time_normal_loop = 
			std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Normal loop took " << time_normal_loop.count() << " microsec\n";

	//Time optimized loop
	begin = std::chrono::steady_clock::now();
	float optimized_loop_result = calculateOptimizedLoop(arr1, arr2, arr_size);
	end = std::chrono::steady_clock::now();

	std::chrono::microseconds time_optim_loop = 
			std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Optimized loop took " << time_optim_loop.count() << " microsec\n";

	EXPECT_FLOAT_EQ(normal_loop_result, optimized_loop_result);
	EXPECT_GT(time_normal_loop.count(), time_optim_loop.count());
}