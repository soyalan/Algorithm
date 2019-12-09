#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	int arr[15][15] = {};
	for (int i = 0; i < 15; i++) arr[0][i] = i;
	for (int t = 0; t < T; t++) {
		int k, n;
		scanf(" %d %d", &k, &n);
		for (int i = 1; i <= k; i++) {
			int sum = 0;
			for (int j = 1; j <= n; j++) {
				sum += arr[i - 1][j];
				arr[i][j] = sum;
			}
		}
		printf("%d\n", arr[k][n]);
	}
	return 0;
}