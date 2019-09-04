#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[9];
	int f[9] = { 1,1,1,1,1,1,1,0,0 };
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	sort(f, f + 9);
	int sum = 0;
	do {
		sum = 0;
		for (int i = 0; i < 9; i++) {
			if (f[i])sum += arr[i];
		}
		if (sum == 100)break;
	} while (next_permutation(f, f + 9));

	for (int i = 0; i < 9; i++)
		if (f[i])printf("%d\n", arr[i]);

	return 0;
}