#include "mymath.h"

#include <math.h>

long double Factorial(long double n) {
	if (n == 0) return 1;
	if (n < 0) return -1;
	long double ans = 1;
	for (long double i = n; i >= 1; i--)
		ans *= i;
	return ans;
}

long double C(long double n, long double k) {
	long double ans = 0;
	ans = Factorial(n) / (Factorial(k) * Factorial(n - k));
	return ans;
}

long double Bin(long double n, long double p, long double a, long double b) {
	long double ans = 0;
	for (long double i = 0; i <= b - a; i++) {
		ans += ((C(n, a + i)) * (powl(p, a + i)) * (powl((1 - p), n - (a + i))));
	}

	return ans;
}

