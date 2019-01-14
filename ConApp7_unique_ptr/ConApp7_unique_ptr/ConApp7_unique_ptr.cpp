// ConApp7_unique_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
//#include <utility>

auto f(std::unique_ptr<int> ptr)
{
	*ptr = 42;
	return ptr;
}
std::unique_ptr<int> GetMem()
{
	auto ptr = std::make_unique<int>();
	return ptr;
}

int main()
{
	auto ptr = GetMem();
	ptr = f(std::move(ptr));
    return 0;
}
// compile with: c++ -std=c++14 -lopenblas
//#include <cmath>
//#include <cstdlib>
//#include <iostream>
//#include <memory> // required for std::unique_ptr, std::make_unique, std::size_t
//#include <utility> // required for std::move
////#include <cblas.h> // required for cblas_daxpy
//
//// create an owned vector initialized to zero
//std::unique_ptr<double[]> new_vector(std::size_t n)
//{
//	return std::make_unique<double[]>(n);
//}
//
//// borrow one vector (v1), seize another (v2), and return an owned vector
//// equal to their sum
//std::unique_ptr<double[]> destructively_add_vectors(
//	std::size_t n,
//	const double* v1,
//	std::unique_ptr<double[]> v2)
//{
//	// sum <- v2
//	std::unique_ptr<double[]> sum = std::move(v2);
//
//	// sum <- v1 + sum
//	//cblas_daxpy(n, 1., v1, 1, sum.get(), 1);
//
//	// for obscure reasons (C++11 §12.8/32), using an explicit std::move here
//	// is actually optional, but we use it anyway for consistency and clarity;
//	// see also: https://stackoverflow.com/a/14856553
//	return std::move(sum);
//}
//
//// borrow two vectors and return an owned vector equal to their sum
//std::unique_ptr<double[]> add_vectors(
//	std::size_t n,
//	const double* v1,
//	const double* v2)
//{
//	// v2_copy <- 0
//	std::unique_ptr<double[]> v2_copy = new_vector(n);
//
//	// v2_copy <- v2
//	//cblas_dcopy(n, v2, 1, v2_copy.get(), 1);
//
//	return destructively_add_vectors(n, v1, std::move(v2_copy));
//}
//
//double fibby(double i)
//{
//	using std::pow;
//	using std::sqrt;
//	const double a = (1. + sqrt(5.)) / 2.;
//	const double b = (1. - sqrt(5.)) / 2.;
//	return (pow(a, i) - pow(b, i)) / sqrt(5);
//}
//
//// create an owned vector initialized to something fun
//std::unique_ptr<double[]> example_vector(std::size_t n)
//{
//	std::unique_ptr<double[]> v = new_vector(n);
//	for (std::size_t i = 0; i != n; ++i) {
//		v[i] = fibby(i);
//	}
//	return v;
//}
//
//// borrow a vector and check that the result is correct
//void check_result(std::size_t n, const double* v)
//{
//	for (std::size_t i = 0; i != n; ++i) {
//		// always use !(difference < epsilon)
//		// rather than (difference >= epsilon)
//		// so NaN can't sneak past the check
//		if (!(std::abs(v[i] - fibby(i) * 2.) < 1e-8)) {
//			std::cerr << "what a cruel, cruel world" << std::endl;
//			std::abort();
//		}
//	}
//}
//
//int main()
//{
//	const std::size_t n = 1024;
//
//	std::unique_ptr<double[]> v1 = example_vector(n);
//	std::unique_ptr<double[]> v2 = example_vector(n);
//
//	// lend v1 and v2 to add_vectors
//	std::unique_ptr<double[]> sum = add_vectors(n, v1.get(), v2.get());
//
//	// lend sum to check_result
//	check_result(n, sum.get());
//
//	// reset sum (actually optional, since the following line will
//	// automatically cause this to happen anyway)
//	sum.reset();
//
//	// lend v1 and relinquish v2 to destructively_add_vectors
//	sum = destructively_add_vectors(n, v1.get(), std::move(v2));
//
//	// lend sum to check_result
//	check_result(n, sum.get());
//
//	// v1 and sum are deleted automatically;
//	// yay no memory leaks \o/
//}
