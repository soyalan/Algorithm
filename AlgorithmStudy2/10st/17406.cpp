#include <iostream>
#include <algorithm>

using namespace std;

int height, width;
int arr[50][50];
int map[50][50];
int inf[6][3];
int res = 0x7fffffff;

void move(int y1, int y2, int x1, int x2) {
	while (y1 != y2 || x1 != x2) {
		int y = y1, x = x1;
		int temp = map[y][x];
		while (y < y2) {
			map[y][x] = map[y + 1][x];
			y++;
		}
		while (x < x2) {
			map[y][x] = map[y][x + 1];
			x++;
		}
		while (y > y1) {
			map[y][x] = map[y - 1][x];
			y--;
		}
		while (x > x1 + 1) {
			map[y][x] = map[y][x - 1];
			x--;
		}
		map[y][x] = temp;

		y1++;
		y2--;
		x1++;
		x2--;
	}
}

void copy() {
	for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) map[i][j] = arr[i][j];
}

void score() {
	int tmp = 0x7fffffff;
	for (int i = 0; i < height; i++) {
		int sum = 0;
		for (int j = 0; j < width; j++) {
			sum += map[i][j];
		}
		if (sum < tmp) tmp = sum;
	}
	if (tmp < res) res = tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int K;
	cin >> height >> width >> K;
	for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) cin >> arr[i][j];

	for (int k = 0; k < K; k++) cin >> inf[k][0] >> inf[k][1] >> inf[k][2];

	int tmp[6];
	for (int i = 0; i < K; i++) tmp[i] = i;

	do {
		copy();
		for (int i = 0; i < K; i++) {
			int r = inf[tmp[i]][0], c = inf[tmp[i]][1], s = inf[tmp[i]][2];
			int y1 = r - s - 1, y2 = r + s - 1, x1 = c - s - 1, x2 = c + s - 1;
			move(y1, y2, x1, x2);
		}
		score();

	} while (next_permutation(tmp, tmp + K));

	cout << res << "\n";

	return 0;
}