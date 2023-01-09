#include <stdio.h>

int f(int a, int b, int c, int d, int n) {
	int result = 0;
	int ab = a * b;
	int cd = c * d;
	int cde = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j) {
			result += ab + cde + j;
		}
		cde += cd;
	}
	return result;
}

int main() {
	printf("%d\n", f(1, 2, 3, 4, 5));
	printf("%d\n", f(2, 3, 4, 5, 6));
	printf("%d\n", f(6, 5, 4, 3, 2));
	printf("%d\n", f(5, 4, 3, 2, 1));
}
