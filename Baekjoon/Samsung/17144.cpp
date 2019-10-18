#include <stdio.h>
#include <iostream>

using namespace std;

int height, width, T;
int map[51][51];
pair<int, int> ac1;
pair<int, int> ac2;

void dust() {
	int arr[51][51] = { 0 };

	int dy[] = { 0,0,-1,1 };
	int dx[] = { -1,1,0,0 };
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int up = 0, down = 0, left = 0, right = 0, count = 0, sum = 0;
			for (int d = 0; d < 4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (nx >= 0 && nx < width && ny >= 0 && ny < height && map[ny][nx] != -1) {
					if (d == 0) {
						left = 1;
					}
					else if (d == 1) {
						right = 1;
					}
					else if (d == 2) {
						up = 1;
					}
					else {
						down = 1;
					}
				}
			}

			count = left + right + up + down + 1;
			if (left) {
				arr[i][j - 1] += (map[i][j] / 5);
			}
			if (right) {
				arr[i][j + 1] += (map[i][j] / 5);
			}
			if (up) {
				arr[i - 1][j] += (map[i][j] / 5);
			}
			if (down) {
				arr[i + 1][j] += (map[i][j] / 5);
			}
			arr[i][j] += (map[i][j] - ((map[i][j] / 5) * (count - 1)));
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = arr[i][j];
		}
	}
}

void air() {
	for (int i = ac1.first - 1; i > 0; i--) {
		map[i][0] = map[i - 1][0];
	}
	for (int j = 0; j < width - 1; j++) {
		map[0][j] = map[0][j + 1];
	}
	for (int i = 0; i < ac1.first; i++) {
		map[i][width - 1] = map[i + 1][width - 1];
	}
	for (int j = width - 1; j > 1; j--) {
		map[ac1.first][j] = map[ac1.first][j - 1];
	}
	map[ac1.first][1] = 0;

	for (int i = ac2.first + 1; i < height - 1; i++) {
		map[i][0] = map[i + 1][0];
	}
	for (int i = 0; i < width - 1; i++) {
		map[height - 1][i] = map[height - 1][i + 1];
	}
	for (int i = height - 1; i > ac2.first; i--) {
		map[i][width - 1] = map[i - 1][width - 1];
	}
	for (int i = width - 1; i > 1; i--) {
		map[ac2.first][i] = map[ac2.first][i - 1];
	}
	map[ac2.first][1] = 0;
}

int main() {
	cin >> height >> width >> T;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf(" %d", &map[i][j]);
			if (map[i][j] == -1) {
				if (ac1.first == 0) {
					ac1.first = i;
					ac1.second = j;
				}
				else {
					ac2.first = i;
					ac2.second = j;
				}
			}
		}
	}

	for (int t = 0; t < T; t++) {
		dust();
		air();
	}

	int cnt = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j] > 0) cnt += map[i][j];
		}
	}
	printf("%d\n", cnt);

	return 0;
}