#include <stdio.h>

int main() {

	int N;
	scanf("%d", &N);
	int max = -1000001, min = 1000001;
	for (int i = 0; i < N; i++) {
		int n;
		scanf(" %d", &n);
		if (n > max) max = n;
		if (n < min) min = n;
	}
	printf("%d %d\n", min, max);

	return 0;
}