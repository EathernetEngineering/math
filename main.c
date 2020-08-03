#include "mymath.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc > 5) {
		printf("Expected 4 arguments");
		return -5;
	} else if (argc < 3) {
		printf("Expected 4 argumetns");
		return -1;
	}
	long double n = strtold(argv[1], &argv[1]);
	long double p = strtold(argv[2], &argv[2]);
	long double a = strtold(argv[3], &argv[3]);
	long double b = strtold(argv[4], &argv[4]);

	printf("%Lf\n", Bin(n, p, a, b));

	return 0;
}
