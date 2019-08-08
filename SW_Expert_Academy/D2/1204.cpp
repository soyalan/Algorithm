#include <iostream>
#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int test;
		scanf("%d", &test);
		int arr[101] = { 0 };
		for (int k = 0; k < 1000; k++) {
			int score;
			scanf("%d", &score);
			arr[score]++;
		}
		int max = 0;
		int maxscore = 0;
		for (int k = 1; k < 101; k++) {
			if (max <= arr[k]) {
				max = arr[k];
				maxscore = k;
			}
		}

		printf("#%d %d\n", test, maxscore);
	}

	return 0;
}