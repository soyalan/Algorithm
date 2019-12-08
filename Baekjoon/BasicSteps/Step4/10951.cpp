#include <stdio.h>

int main() {

	int A, B;
	char a;
	while ((a = getchar()) != EOF) {
		scanf(" %d", &B);
		getchar();
		A = a - '0';
		if (!A && !B) break;
		printf("%d\n", A + B);
	}

	return 0;
}