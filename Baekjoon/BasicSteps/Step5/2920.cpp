#include <stdio.h>

int main() {

	int temp;
	bool as = true;
	bool de = true;
	scanf("%d", &temp);
	for (int i = 1; i < 8; i++) {
		int n;
		scanf(" %d", &n);
		if (temp > n) {

		}
		if (temp < n) {

		}
		temp = n;
	}
	
	return 0;
}