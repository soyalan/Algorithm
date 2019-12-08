#include <stdio.h>
#include <iostream>
#include <algorithm>

int main() {

	int N;
	scanf("%d", &N);
	double arr[1001] = { 0 };
	int max = 0;
	for (int i = 0; i < N; i++) {
		scanf(" %lf", &arr[i]);
		if (max < arr[i]) max = arr[i];
	}
	double sum = 0;
	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] * 100 / max;
		sum += arr[i];
	}
	printf("%.2lf\n", sum / N);


	return 0;
}