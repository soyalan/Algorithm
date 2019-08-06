#include <iostream>
#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int arr[10];
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[j]);
			if (arr[j] % 2 == 1) {
				sum += arr[j];
			}
		}
		printf("#%d %d\n", i + 1, sum);
	}

	return 0;
}