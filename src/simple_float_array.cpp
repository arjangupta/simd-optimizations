#include <iostream>

#include <simdpp/simd.h>

#define arr_size 10000

int main()
{
	//Data
	// size_t arr_size = 10000;//296046 * 634
	double* testDataOne   = new double[arr_size];
	double* testDataTwo   = new double[arr_size];

	for (size_t i = 0; i < arr_size; ++i)
	{
		//Arbitrarily chosen functions
		testDataOne[i] = sin(i);
		testDataTwo[i] = tan(i);
	}
    
    //simdpp::float64<BE/4>* volatile f32;
    simdpp::float64<arr_size> a = simdpp::load(testDataOne);
    simdpp::float64<arr_size> b = simdpp::load(testDataTwo);
    simdpp::float64<arr_size> c = a - b;
    simdpp::float64<arr_size> d = c * c;
    double val = simdpp::reduce_add(d);
    
    std::cout<<val<<std::endl;

    // std::cout << testDataOne[1] + testDataThree[1] * (testDataTwo[1] - testDataOne[1]) << std::endl;

    double result = 0;

    for (size_t i = 0; i < arr_size; ++i)
    {
        double diff = testDataOne[i] - testDataTwo[i];
        result += diff * diff;
    }

    std::cout << result << std::endl;

    return 0;
}