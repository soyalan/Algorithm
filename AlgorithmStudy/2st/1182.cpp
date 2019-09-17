#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, S;
	cin >> N >> S;
	int arr[20] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int cnt = 0, sum;
	for (int i = 0; i < N; i++) {
		int check[20] = { 0 };
		for (int j = 0; j <= i; j++) {
			check[j] = 1;
		}
		sort(check, check + N);
		do {
			sum = 0;
			for (int k = 0; k < N; k++) {
				if (check[k])sum += arr[k];
			}
			if (sum == S)cnt++;
		} while (next_permutation(check, check + N));
	}

	printf("%d\n", cnt);

	return 0;
}