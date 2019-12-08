#include <stdio.h>
#include <iostream>
#include <algorithm>

int main() {

	int N;
	scanf(" %d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		char a;
		int score = 0;
		int cnt = 0;
		while ((a = getchar()) != '\n') {
			if (a == 'O') {
				cnt++;
				score += cnt;
			}
			else {
				cnt = 0;
			}
		}
		printf("%d\n", score);
	}


	return 0;
}