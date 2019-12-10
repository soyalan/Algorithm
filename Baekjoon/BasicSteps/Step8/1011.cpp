#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int x, y;
		scanf(" %d %d", &x, &y);
		int temp = y - x;
		int n = sqrt(temp);
		if ((n * n) == temp) {
			printf("%d\n", n * 2 - 1);
		}
		else {
			if ((n * n + (((n + 1) * (n + 1)) - (n * n) + 1) / 2) > temp) {
				printf("%d\n", n * 2);
			}
			else {
				printf("%d\n", (n + 1) * 2 - 1);
			}
		}
	}

	return 0;
}