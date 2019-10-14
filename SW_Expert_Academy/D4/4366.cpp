/*
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int check2(int arr[], int n) {
	int res = 0;
	int mul = 1;
	for (int i = n - 1; i >= 0; i--) {
		res = res + arr[i] * mul;
		mul *= 2;
	}
	return res;
}

int check3(int arr[], int n) {
	int res = 0;
	int mul = 1;
	for (int i = n - 1; i >= 0; i--) {
		res = res + arr[i] * mul;
		mul *= 3;
	}
	return res;
}

int main() {

	int T;
	cin >> T;
	getchar();
	for (int t = 0; t < T; t++) {
		int arr2[41];
		int arr3[41];
		char a = 'A';
		int idx2 = 0, idx3 = 0 ;
		while ((a = getchar()) != '\n') {
			arr2[idx2++] = a - '0';
		}
		while ((a = getchar()) != '\n') {
			arr3[idx3++] = a - '0';
		}

		int res2[41] = { 0 };
		for (int i = 0; i < idx2; i++) {
			arr2[i] = !arr2[i];
			res2[i] = check2(arr2, idx2);
			arr2[i] = !arr2[i];
		}
		int* z = find(arr2, arr2 + idx2, 14);
		for (int i = 0; i < idx3; i++) {
			if (arr3[i] == 0) {
				arr3[i] = 1;
				res3[i][0] = check3(arr3, idx3);
				arr3[i] = 2;
				res3[i][0] = check3(arr3, idx3);
				arr3[i] = 0;
			}
			else if (arr3[i] == 1) {
				arr3[i] = 0;
				res3[i][0] = check3(arr3, idx3);
				arr3[i] = 2;
				res3[i][0] = check3(arr3, idx3);
				arr3[i] = 1;
			}
			else {
				arr3[i] = 0;
				res3[i][0] = check3(arr3, idx3);
				arr3[i] = 1;
				res3[i][0] = check3(arr3, idx3);
				arr3[i] = 2;
			}
		}
	}

	return 0;
}
*/