#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int H, W, N;
		scanf(" %d %d %d", &H, &W, &N);
		int floor = N;
		int room = 1;
		while (floor > H) {
			floor -= H;
			room++;
		}
		printf("%d\n", (floor * 100) + room);
	}

	return 0;
}