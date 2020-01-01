#include <iostream>
#include <stdlib.h>

using namespace std;

int minimum(int a, int b, int c) {
	int temp;
	if (a > b) {
		temp = b;
		if (b > c) temp = c;
	}
	else {
		temp = a;
		if (a > c) temp = c;
	}
	return temp;
}

int main() {

	int n;
	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		int a = 0x7FFFFFFF, b = 0x7FFFFFFF, c = 0x7FFFFFFF;
		a = arr[i - 1] + 1;
		if (i % 2 == 0) b = arr[i / 2] + 1;
		if (i % 3 == 0) c = arr[i / 3] + 1;
		arr[i] = minimum(a, b, c);
	}

	cout << arr[n] << "\n";

	free(arr);

	return 0;
}