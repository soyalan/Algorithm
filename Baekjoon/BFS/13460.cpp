/*
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int width, height;
int redx, redy, bluex, bluey;
char arr[10][10];
bool goal;

int bfs() {
	return -1;
}

int main() {
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				redx = j;
				redy = i;
			}
			if (arr[i][j] == 'B') {
				bluex = j;
				bluey = i;
			}
		}
	}

	printf("%d\n", bfs());

	return 0;
}
*/