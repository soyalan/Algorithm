#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int height, width, range;
int map[15][15];
int arr[15][15];
int archer[15];
int enemy;

void copy() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = arr[i][j];
		}
	}
}

int hunt() {
	int cnt = 0;
	int arc[3];
	int attack[3][2];
	for (int i = 0; i < width; i++) if (archer[i] == 1) arc[cnt++] = i;
	cnt = enemy;

	int res = 0;
	while (cnt > 0) {
		for (int i = 0; i < 3; i++) {
			attack[i][0] = -1;
			attack[i][1] = -1;
			for (int r = 1; r <= range; r++) {
				int y = 1;
				int x = r - y;
				bool find = false;
				while (x > 0 && !find) {
					int ny = height - y;
					int nx = arc[i] - x;
					if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
						if (map[ny][nx]) {
							attack[i][0] = ny;
							attack[i][1] = nx;
							find = true;
						}
					}
					y++;
					x--;
				}
				while (y >= 1 && !find) {
					int ny = height - y;
					int nx = arc[i] + x;
					if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
						if (map[ny][nx]) {
							attack[i][0] = ny;
							attack[i][1] = nx;
							find = true;
						}
					}
					x++;
					y--;
				}

				if (find) break;
			}
		}

		for (int i = 0; i < 3; i++) {
			int y = attack[i][0];
			int x = attack[i][1];
			if (y == -1) continue;
			if (map[y][x]) {
				map[y][x] = 0;
				cnt--;
				res++;
			}
		}

		for (int i = 0; i < width; i++) {
			if (map[height - 1][i]) cnt--;
		}
		for (int i = height - 1; i > 0; i--) {
			for (int j = 0; j < width; j++) {
				map[i][j] = map[i - 1][j];
			}
		}
		for (int i = 0; i < width; i++) map[0][i] = 0;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> height >> width >> range;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) enemy++;
		}
	}

	for (int i = width - 3; i < width; i++) archer[i] = 1;

	int res = 0;
	do {
		copy();
		int tmp = hunt();
		res = max(res, tmp);
	} while (next_permutation(archer, archer + width));

	cout << res << "\n";

	return 0;
}