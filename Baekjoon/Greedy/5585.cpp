#include <stdio.h>

int main() {

	int money;
	scanf("%d", &money);
	money = 1000 - money;
	int arr[] = { 1, 5, 10, 50, 100, 500 };
	int n = 5;
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