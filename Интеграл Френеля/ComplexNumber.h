#pragma once
#include<fstream>

class ComplexNumber {
public:
	ComplexNumber(double _real = 0, double _imaginary = 0);

	double getReal() const;
	double getImaginary() const;
	double abs() const;

	ComplexNumber& operator+=(const ComplexNumber& other);
	ComplexNumber& operator-=(const ComplexNumber& other);
	ComplexNumber& operator*=(const ComplexNumber& other);
	ComplexNumber& operator/=(const ComplexNumber& other);

private:
	double real;
	double imaginary;
};

ComplexNumber operator+(ComplexNumber numb1, const ComplexNumber& numb2);
ComplexNumber operator-(ComplexNumber numb1, const ComplexNumber& numb2);
ComplexNumber operator*(ComplexNumber numb1, const ComplexNumber& numb2);
ComplexNumber operator/(ComplexNumber numb1, const ComplexNumber& numb2);