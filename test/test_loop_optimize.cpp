#include "loop_optimize.h"

#include <gtest/gtest.h>
#include <chrono>
#include <iostream>

using namespace simd_optimizations;

TEST(loopOptimizeUnitTest, timingTests)
{
	size_t arr_size = 5000;
	float* arr1 = new float[arr_size];
	float* arr2 = new float[arr_size];

	//Timing vars
	std::chrono::steady_clock::time_point begin, end;

	//Time normal loop
	begin = std::chrono::steady_clock::now();
	float normal_loop_result = calculateNormalLoop();
	end = std::chrono::steady_clock::now();

	std::chrono::microseconds time_normal_loop = 
			std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Normal loop took " << time_normal_loop << " microsec\n";

	//Time optimized loop
	begin = std::chrono::steady_clock::now();
	float optimized_loop_result = calculateOptimizedLoop();
	end = std::chrono::steady_clock::now();

	std::chrono::microseconds time_optim_loop = 
			std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Optimized loop took " << time_optim_loop << " microsec\n";

	EXPECT_EQ(normal_loop_result, optimized_loop_result);
	EXPECT_GT(normal_loop_result, optimized_loop_result);
}