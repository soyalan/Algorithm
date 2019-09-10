#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int N;
	cin >> N;
	int arr[51];
	int brr[51];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> brr[i];
	}

	sort(arr, arr + N);
	sort(brr, brr + N, compare);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (arr[i] * brr[i]);
	}
	printf("%d\n", sum);

	return 0;
}