#include <stdio.h>
#include <iostream>
#include <algorithm>

int main() {

	int arr[42] = { 0 };
	for (int i = 0; i < 10; i++) {
		int temp;
		scanf(" %d", &temp);
		arr[temp % 42]++;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (arr[i])cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}