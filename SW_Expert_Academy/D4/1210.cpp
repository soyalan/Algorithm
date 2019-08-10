#include <stdio.h>
#include <iostream>

int find(int arr[100][100], int s) {
	int x = s, y = 0;
	int direction = 1; // 1 down, 2 left, 3 right
	do {
		switch (direction) {
		case 1:
			if (x != 0) {
				if (arr[y][x - 1] == 1) {
					direction = 2;
					x--;
					break;
				}
			}
			if (x != 99) {
				if (arr[y][x + 1] == 1) {
					direction = 3;
					x++;
					break;
				}
			}
			y++;
			break;
		case 2:
			if (x != 0) {
				if (arr[y][x - 1] == 1) {
					x--;
					break;
				}
			}
			direction = 1;
			y++;
			break;
		case 3:
			if (x != 99) {
				if (arr[y][x + 1] == 1) {
					x++;
					break;
				}
			}
			direction = 1;
			y++;
			break;
			
		}
	} while (y != 99);

	if (arr[y][x] == 2)
		return s;
	else
		return 100;
}

int main() {

	for (int k = 0; k < 10; k++) {
		int n;
		scanf("%d", &n);

		int arr[100][100];
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		int result = 100;
		for (int i = 0; i < 100; i++) {
			if (arr[0][i] == 1)
				result = find(arr, i);
			if (result != 100)
				break;
		}
		printf("#%d %d\n", k + 1, result);
	}

	return 0;
}