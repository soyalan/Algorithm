#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n;
	int number[13];
	int arr[13];
	while (1) {
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++)	cin >> number[i];
		for (int i = 0; i < 6; i++)	arr[i] = 1;
		for (int i = 6; i < n; i++)	arr[i] = 0;
		sort(arr, arr + n, compare);
		do {
			for (int i = 0; i < n; i++) {
				if (arr[i] == 1)printf("%d ", number[i]);
			}
			printf("\n");
		} while (prev_permutation(arr, arr + n));
			

		printf("\n");
	}


	return 0;
}