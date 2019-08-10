#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	long long int number;
	scanf("%lld", &number);
	int arr[10001];
	int cnt = 0;
	bool zero = false;
	while (number != 0) {
		arr[cnt++] = number % 10;
		number /= 10;
		if (arr[cnt - 1] == 0)
			zero = true;
	}

	for (int i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	if (zero) {
		int sum = 0;
		for (int i = 0; i < cnt; i++) {
			sum += arr[i];
		}
		if (sum % 3 == 0) {
			sort(arr, arr + cnt);
			long long int result = 0;
			while (cnt != 0) {
				result = (result * 10) + arr[cnt-- - 1];
			}
			printf("%lld\n", result);
		}
		else
			printf("-1\n");
	}
	else
		printf("-1\n");

	return 0;
}