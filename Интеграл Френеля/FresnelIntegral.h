#pragma once
#include<vector>
#include<cmath>
#include<ppl.h>
#include"ComplexNumber.h"
#include"complexFunctions.h"

class FresnelIntegral {
public:
	FresnelIntegral(double _lambda, double _z, const std::vector<std::vector<ComplexNumber>> _intensities, double _realHeight, double _realWidth);

	std::vector<std::vector<ComplexNumber>> integrate();

private:
	double lambda; // длина волны
	double z; // расстояние до изображения
	double k; // волновое число
	std::vector<std::vector<ComplexNumber>> amplitudes; // исходное распределение интенсивностей
	double realHeight; // физическая высота изображения
	double realWidth; // физическая ширина изображения
	double dx;
	double dy;
};