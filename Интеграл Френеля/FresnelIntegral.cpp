#include "FresnelIntegral.h"

FresnelIntegral::FresnelIntegral(double _lambda, double _z, const std::vector<std::vector<double>> _intensities, double _realHeight, double _realWidth) {
	lambda = _lambda;
	z = _z;
	k = 2 * std::acos(-1) / lambda;
	realHeight = _realHeight;
	realWidth = _realWidth;
	dy = realHeight / _intensities.size();
	dx = realWidth / _intensities[0].size();
}

std::vector<std::vector<ComplexNumber>> FresnelIntegral::integrate() {
	std::vector<std::vector<ComplexNumber>> integratingResult(intensities.size(), std::vector<ComplexNumber>(intensities[0].size()));

	concurrency::parallel_for(size_t(0), integratingResult.size(), [&](size_t y) {
		concurrency::parallel_for(size_t(0), integratingResult[y].size(), [&](size_t x) {
			ComplexNumber result(0, 0);
			for (size_t yprime(0); yprime < intensities.size(); ++yprime) {
				for (size_t xprime(0); xprime < intensities[yprime].size(); ++xprime) {
					result += intensities[yprime][xprime] * complexExp(k * (std::pow(x - xprime, 2) + std::pow(y - yprime, 2))) * dx * dy;
				}
			}
			result *= complexExp(k * z) / (I * lambda * z);
			integratingResult[y][x] = result;
		});
	});

	return integratingResult;
}