#include <stdint.h>
#include <math.h>

namespace Math {
	constexpr double pi = 245850922.0 / 78256779.0;
	constexpr double e = 2.71828182845904523536028747135266249775724709369995;
	constexpr uint64_t TrigPrecision = 8;

	double Radians(double degrees);
	uint64_t factorial(uint64_t x);
	double sin(double angleInRadians);
	double cos(double angleInRadians);
	double tan(double angleInRadians);
	double power(double base, uint64_t exponant);
	double Bernoulli_2n(size_t index);
	double ζ(double s);

	namespace {
		enum Quadrants
		{
			FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4
		};

		struct TrigData
		{
			uint16_t quadrant;
			double EquivelentAngle;
		};

		TrigData  GetEquivelentAngle(double angleInRadians) {
			if (angleInRadians <= pi / 2.0) return { FIRST, angleInRadians };

			double angle = angleInRadians;

			while (angle > 2 * pi) {
				angle -= pi;
			}

			if (angle <= pi / 2.0) return { FIRST, angle };
			if (angle > pi / 2.0 && angle <= pi) return { SECOND, pi - angle };
			if (angle > pi && angle <= 3 * pi / 2) return { THIRD, angle - pi };
			if (angle > 3 * pi / 2 && angle <= 2 * pi) return { FOURTH, pi - angle };
		}
	}

	double Radians(double degrees) {
		return (pi * degrees) / 180.0;
	}

	uint64_t factorial(uint64_t x)
	{
		if (x == 1) return 1;

		uint64_t res = 1;

		for (uint64_t i = 1; i < x + 1; i++)
			res *= i;

		return res;
	}

	double sin(double angleInRadians) {

		bool Plus = false;

		TrigData Data = GetEquivelentAngle(angleInRadians);
		double angle = Data.EquivelentAngle;
		double res = angle;

		for (uint64_t i = 1; i < TrigPrecision; i++)
			if (Plus) {
				res += (power(angle, (2 * i) + 1)) / factorial((2 * i) + 1);
				Plus = !Plus;
			} else {
				res -= (power(angle, (2 * i) + 1)) / factorial((2 * i) + 1);
				Plus = !Plus;
			}

		if (Data.quadrant == THIRD || Data.quadrant == FOURTH)
			return -res;
		else return res;
	}

	double cos(double angleInRadians) {


		bool Plus = false;

		TrigData Data = GetEquivelentAngle(angleInRadians);
		double angle = Data.EquivelentAngle;
		double res = 1;

		for (uint64_t i = 1; i < TrigPrecision; i++)
			if (Plus) {
				res += power(angle, 2 * i) / factorial(2 * i);
				Plus = !Plus;
			} else {
				res -= power(angle, 2 * i) / factorial(2 * i);
				Plus = !Plus;
			}

		if (Data.quadrant == SECOND || Data.quadrant == THIRD)
			return -res;
		else return res;
	}

	double tan(double angleInRadians) {
		bool Plus = false;

		TrigData Data = GetEquivelentAngle(angleInRadians);
		double angle = Data.EquivelentAngle;
		double res = angle;

		if (angle == pi / 2) throw std::invalid_argument("Tan(π/2) is undefined\n");

		for (uint64_t i = 1; i < TrigPrecision; i++)
			if (Plus) {
				res += (power(angle, (2 * i) + 1)) / factorial((2 * i) + 1);
				Plus = !Plus;
			} else {
				res -= (power(angle, (2 * i) + 1)) / factorial((2 * i) + 1);
				Plus = !Plus;
			}

		if (Data.quadrant == SECOND || Data.quadrant == FOURTH)
			return -res;
		else return res;
	}

	double power(double base, uint64_t exponant) {
		double res = 1;
		for (uint64_t i = 0; i < exponant; i++)
			res *= base;
		return res;
	}

	double Bernoulli_2n(size_t n) {
		power(-1.0, n + 1)* (2 * factorial(2 * n) / power(2 * pi, 2 * n))* ζ(2 * n);
	}
	double ζ(double s) {

	}
}
