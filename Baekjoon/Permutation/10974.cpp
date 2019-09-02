#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int arr[10];
	cin >> n;

	for (int i = 0; i < n; i++) {
		arr[i] = i+1;
	}

	do {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(arr, arr + n));

	return 0;
}