#include <stdio.h>

int main() {

	int max = 0, maxidx = 0;
	for (int i = 0; i < 9; i++) {
		int n;
		scanf(" %d", &n);
		if (n > max) {
			max = n;
			maxidx = i;
		}
	}
	printf("%d\n%d\n", max, maxidx + 1);

	return 0;
}