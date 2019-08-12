#include <stdio.h>
#include <iostream>

int exponentiation(int num, int n) {
	if (n == 1) {
		return num;
	}
	return (num * exponentiation(num, n-1));
}


int main() {

	for (int k = 0; k < 10; k++) {
		int t;
		scanf("%d", &t);
		int num, n;
		scanf("%d %d", &num, &n);
		int result = exponentiation(num, n);

		printf("#%d %d\n", k+1, result);
	}

	return 0;
}