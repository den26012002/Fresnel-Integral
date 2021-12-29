#include<ppl.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include"ComplexNumber.h"
#include"complexFunctions.h"
#include"FresnelIntegral.h"

std::ifstream finMatrix("amplitudes.txt");
std::ifstream finConfig("config.txt");
std::ofstream fout("resultAmplitudes.txt");

int main()
{
	double lambda, z, realHeight, realWidth;
	finConfig >> lambda >> z >> realHeight >> realWidth;

	size_t height, width;
	finMatrix >> height >> width;
	std::vector<std::vector<ComplexNumber>> startMatrix(height, std::vector<ComplexNumber>(width));
	for (size_t i(0); i < height; ++i) {
		for (size_t j(0); j < width; ++j) {
			double amplitude;
			finMatrix >> amplitude;
			startMatrix[i][j] = amplitude;
		}
	}

	FresnelIntegral fresnelIntegral(lambda, z, startMatrix, realHeight, realWidth);
	auto integrationResult = fresnelIntegral.integrate();
	for (auto& line : integrationResult) {
		for (auto number : line) {
			fout << '(' << number.getReal() << '+' << number.getImaginary() << "j)";
		}
	}

	return 0;
}