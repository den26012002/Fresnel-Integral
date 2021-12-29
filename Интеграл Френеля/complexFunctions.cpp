#include<cmath>
#include"complexFunctions.h"

ComplexNumber complexExp(double x) {
	return ComplexNumber(std::cos(x) + I * std::sin(x));
}