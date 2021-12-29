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
	double lambda; // ����� �����
	double z; // ���������� �� �����������
	double k; // �������� �����
	std::vector<std::vector<ComplexNumber>> amplitudes; // �������� ������������� ��������������
	double realHeight; // ���������� ������ �����������
	double realWidth; // ���������� ������ �����������
	double dx;
	double dy;
};