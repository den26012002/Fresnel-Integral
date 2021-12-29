#include<cmath>
#include<string>
#include"ComplexNumber.h"

ComplexNumber::ComplexNumber(double _real, double _imaginary) {
	real = _real;
	imaginary = _imaginary;
}

double ComplexNumber::getReal() const {
	return real;
}

double ComplexNumber::getImaginary() const {
	return imaginary;
}

double ComplexNumber::abs() const {
	return std::pow(real * real + imaginary * imaginary, 0.5);
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other) {
	real += other.real;
	imaginary += other.imaginary;
	return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other) {
	real -= other.real;
	imaginary -= other.imaginary;
	return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other) {
	real = real * other.real - imaginary * other.imaginary;
	imaginary = real * other.imaginary + imaginary * other.real;
	return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other) {
	real = (real * other.real + imaginary * other.imaginary) / std::pow(other.abs(), 2);
	imaginary = (other.real * imaginary - real * other.imaginary) / std::pow(other.abs(), 2);
	return *this;

}

ComplexNumber operator+(ComplexNumber numb1, const ComplexNumber& numb2) {
	return numb1 += numb2;
}

ComplexNumber operator-(ComplexNumber numb1, const ComplexNumber& numb2) {
	return numb1 -= numb2;
}

ComplexNumber operator*(ComplexNumber numb1, const ComplexNumber& numb2) {
	return numb1 *= numb2;
}

ComplexNumber operator/(ComplexNumber numb1, const ComplexNumber& numb2) {
	return numb1 /= numb2;
}

std::ofstream& operator<<(std::ofstream& cout, ComplexNumber& numb) {
	cout << '(' << numb.getReal() << '+' << numb.getImaginary() << "j)";
	return cout;
}