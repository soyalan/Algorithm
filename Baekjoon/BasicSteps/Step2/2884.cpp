#include <stdio.h>

int main() {

	int H, M;
	scanf("%d %d", &H, &M);

	if (M >= 45) {
		printf("%d %d\n", H, M - 45);
	}
	else {
		if (H > 0) {
			printf("%d %d\n", H - 1, 15 + M);
		}
		else {
			printf("23 %d\n", 15 + M);
		}
	}

	return 0;
}