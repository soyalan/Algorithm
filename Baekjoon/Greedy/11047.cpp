#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n, money;
	scanf("%d %d", &n, &money);
	int arr[11];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	n--;
	int cnt = 0;
	while (money != 0) {
		if (arr[n] > money) {
			n--;
			continue;
		}
		while (arr[n] <= money) {
			money -= arr[n];
			cnt++;
		}
	}

	printf("%d\n", cnt);


	return 0;
}