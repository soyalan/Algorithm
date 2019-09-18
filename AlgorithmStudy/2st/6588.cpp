/*
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[1000002];

void f(int k) {
	for (int i = 2; i <= sqrt(k); i++) {
		if (!arr[i]) continue;
		for (int j = i * 2; j <= k; j += i) {
			arr[j] = 0;
		}
	}
}

int main() {
	int N = 1000000;
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}
	f(N);

	while (1) {
		cin >> N;
		if (N == 0)break;	

		int i, j, sum;

		for (i = 2; i <= N; i++) {
			if (arr[i] == 0) continue;
			else if (arr[i] > N) break;
			sum = 0;
			for (j = i; j <= N; j++) {
				if (arr[j] == 0) continue;
				else if (arr[j] > N) break;
				sum = arr[i] + arr[j];
				if (sum == N) break;
				else if (sum > N)break;

			}
			if (sum == N) break;
		}

		printf("%d = %d + %d\n", N, arr[i], arr[j]);

	}
	return 0;
}
*/