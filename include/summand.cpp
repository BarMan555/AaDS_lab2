#pragma once
#include <iostream>

// Слагаемое в многочлене
template<class T> 
struct summand {
	T coeff;
	int degree;

	friend std::ostream& operator<<(std::ostream& stream, const summand<T>& sum) {
		stream << sum.coeff << "X^" << sum.degree;
		return stream;
	}
};