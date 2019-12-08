#include <stdio.h>

int main() {

	while (1) {
		int A, B;
		scanf("%d %d", &A, &B);
		if (!A && !B) break;
		printf("%d\n", A + B);
	}

	return 0;
}