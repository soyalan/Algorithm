#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int number;
	cin >> number;
	int arr[3] = { 0 };
	int cnt = 99;
	if (number < 100) {
		printf("%d\n", number);
	}
	else {
		if (number == 1000)number = 999;
		for (int i = 100; i <= number; i++) {
			int n = i;
			for (int j = 2; j >= 0; j--) {
				arr[j] = n % 10;
				n /= 10;
			}
			if ((arr[2] - arr[1]) == (arr[1] - arr[0]))cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}