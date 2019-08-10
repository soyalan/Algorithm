#include <stdio.h>
#include <iostream>

int main() {

	for (int k = 0; k < 10; k++) {
		int n;
		scanf("%d", &n);

		int arr[101][101];
		int max = 0;
		int vsum[101] = { 0 };
		int dsum = 0;
		for (int i = 0; i < 100; i++) {
			int hsum = 0;
			for (int j = 0; j < 100; j++) {
				scanf("%d", &arr[i][j]);
				hsum += arr[i][j];
				vsum[j] += arr[i][j];
				if (i == j)dsum += arr[i][j];
			}
			if (max < hsum) max = hsum;
		}
		for (int i = 0; i < 100; i++) {
			if (max < vsum[i])max = vsum[i];
		}
		if (max < dsum) max = dsum;

		printf("#%d %d\n", k + 1, max);
	}
	
}