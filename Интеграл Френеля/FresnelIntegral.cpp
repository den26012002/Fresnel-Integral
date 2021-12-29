#include "FresnelIntegral.h"

FresnelIntegral::FresnelIntegral(double _lambda, double _z, const std::vector<std::vector<ComplexNumber>>& _amplitudes, double _realHeight, double _realWidth) {
	lambda = _lambda;
	z = _z;
	k = 2 * std::acos(-1) / lambda;
	amplitudes = _amplitudes;
	realHeight = _realHeight;
	realWidth = _realWidth;
	dy = realHeight / _amplitudes.size();
	dx = realWidth / _amplitudes[0].size();
}

std::vector<std::vector<ComplexNumber>> FresnelIntegral::integrate() {
	std::vector<std::vector<ComplexNumber>> integratingResult(amplitudes.size(), std::vector<ComplexNumber>(amplitudes[0].size()));

	concurrency::parallel_for(size_t(0), integratingResult.size(), [&](size_t y) {
		concurrency::parallel_for(size_t(0), integratingResult[y].size(), [&](size_t x) {
			ComplexNumber result(0, 0);
			for (size_t yprime(0); yprime < amplitudes.size(); ++yprime) {
				for (size_t xprime(0); xprime < amplitudes[yprime].size(); ++xprime) {
					result += amplitudes[yprime][xprime] * complexExp(k * (std::pow((x - xprime) * dx, 2) + std::pow((y - yprime) * dy, 2)) / (2 * z)) * dx * dy;
				}
			}
			result *= complexExp(k * z) / (I * lambda * z);
			integratingResult[y][x] = result;
		});
	});

	return integratingResult;
}