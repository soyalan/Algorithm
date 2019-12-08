#include <stdio.h>
#include <iostream>
#include <algorithm>

int main() {

	int C;
	scanf(" %d", &C);
	int arr[1001] = { 0 };
	for (int i = 0; i < C; i++) {
		int N;
		scanf(" %d", &N);
		int sum = 0;
		for (int j = 0; j < N; j++) {
			scanf(" %d", &arr[j]);
			sum += arr[j];
		}
		double avg = (double)sum / N;
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j] > avg)cnt++;
		}
		printf("%.3lf%%\n", (double)cnt * 100 / N);
	}


	return 0;
}