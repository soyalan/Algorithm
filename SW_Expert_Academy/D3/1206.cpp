#include <stdio.h>
#include <iostream>

int main() {

	for (int i = 0; i < 10; i++) {
		int n;
		scanf("%d", &n);
		int arr[1001] = { 0 };
		for (int k = 0; k < n; k++) {
			scanf("%d", &arr[k]);
		}

		int sum = 0;
		for (int k = 2; k < n - 2; k++) {
			int max = 0;
			if (arr[k - 2] > max)
				max = arr[k - 2];
			if (arr[k - 1] > max)
				max = arr[k - 1];
			if (arr[k + 1] > max)
				max = arr[k + 1];
			if (arr[k + 2] > max)
				max = arr[k + 2];

			if (max < arr[k])
				sum += (arr[k] - max);
		}
		printf("#%d %d\n", i + 1, sum);
	}

	return 0;
}