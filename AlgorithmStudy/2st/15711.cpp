/*
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long arr[1000002];

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

	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int a, b;
		cin >> a >> b;
		N = a + b;

		int i, j, sum;
		bool check = false;
		for (i = 2; i <= N; i++) {
			if (arr[i] == 0) continue;
			else if (arr[i] > N) break;
			sum = 0;
			for (j = i; j <= N; j++) {
				if (arr[j] == 0) continue;
				else if (arr[j] > N) break;
				sum = arr[i] + arr[j];
				if (sum == N) {
					check = true;
					break;
				}
				else if (sum > N)break;

			}
			if (sum == N) break;
		}
		if (check)printf("YES\n");
		else printf("NO\n");

	}
	return 0;
}
*/