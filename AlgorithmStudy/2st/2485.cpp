/*
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int N;
	cin >> N;
	int arr[100003];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int min = 0x7FFFFFFF;
	int brr[100003];
	for (int i = 0; i < N-1; i++) {
		brr[i] = arr[i + 1] - arr[i];
		if (brr[i] < min) min = brr[i];
	}

	while (min > 1) {
		bool check = true;
		for (int i = 0; i < N - 1; i++) {
			if (brr[i] % min != 0)check = false;
		}
		if (check) break;
		min--;
	}
	
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		int c = (brr[i] / min) - 1;
		if(c) cnt += c;
	}

	printf("%d\n", cnt);

	return 0;
}
*/