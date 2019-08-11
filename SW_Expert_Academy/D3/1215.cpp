#include <stdio.h>
#include <iostream>

int main() {

	for (int k = 0; k < 10; k++) {
		int n;
		scanf("%d ", &n);
		char arr[8][8];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%c ", &arr[i][j]);
			}
		}
		int cnt = 0;
		// °¡·Î Å½»ö
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (j + n - 1 >= 8)
					break;
				int t = 0;
				for (; t < n / 2; t++) {
					if (arr[i][j + t] != arr[i][j + n - t - 1]) {
						break;
					}
				}
				if (t == n / 2) {
					cnt++;
				}
			}
		}
		// ¼¼·Î Å½»ö
		for (int j = 0; j < 8; j++) {
			for (int i = 0; i < 8; i++) {
				if (i + n - 1 >= 8)
					break;
				int t = 0;
				for (; t < n / 2; t++) {
					if (arr[i + t][j] != arr[i + n - t - 1][j]) {
						break;
					}
				}
				if (t == n / 2) {
					cnt++;
				}
			}
		}

		printf("#%d %d\n", k + 1, cnt);
	}

	return 0;
}