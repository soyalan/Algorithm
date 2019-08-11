#include <stdio.h>
#include <iostream>

#define NUM 100

int main() {

	for (int k = 0; k < 10; k++) {
		int out;
		scanf("%d ", &out);
		char arr[NUM][NUM];
		for (int i = 0; i < NUM; i++) {
			for (int j = 0; j < NUM; j++) {
				scanf("%c ", &arr[i][j]);
			}
		}
		int max = 0;
		// °¡·Î Å½»ö
		for (int i = 0; i < NUM; i++) {
			for (int j = 0; j < NUM; j++) {
				for (int n = max; n + j <= NUM; n++) {
					int t = 0;
					for (; t < n / 2; t++) {
						if (arr[i][j + t] != arr[i][j + n - t - 1]) {
							break;
						}
					}
					if (t == n / 2) {
						max = n;
					}
				}
			}
		}
		// ¼¼·Î Å½»ö
		for (int j = 0; j < NUM; j++) {
			for (int i = 0; i < NUM; i++) {
				for (int n = max; n + i <= NUM; n++) {
					int t = 0;
					for (; t < n / 2; t++) {
						if (arr[i + t][j] != arr[i + n - t - 1][j]) {
							break;
						}
					}
					if (t == n / 2) {
						max = n;
					}
				}
			}
		}

		printf("#%d %d\n", k + 1, max);
	}

	return 0;
}