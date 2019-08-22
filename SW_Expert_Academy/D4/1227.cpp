#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int arr[100][100];
bool way;

void bfs(int starty, int startx) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(starty, startx));
	bool visited[100][100] = { false };
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x])continue;
		if (arr[y][x] == 3) {
			way = true;
			break;
		}
		if (arr[y][x - 1] != 1) {
			q.push(pair<int, int>(y, x - 1));
		}
		if (arr[y][x + 1] != 1) {
			q.push(pair<int, int>(y, x + 1));
		}
		if (arr[y - 1][x] != 1) {
			q.push(pair<int, int>(y - 1, x));
		}
		if (arr[y + 1][x] != 1) {
			q.push(pair<int, int>(y + 1, x));
		}
		visited[y][x] = true;
	}
}

int main() {
	for (int k = 0; k < 10; k++) {

		int n;
		cin >> n;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}

		way = false;
		bfs(1, 1);

		if (way)
			printf("#%d 1\n", k + 1);
		else
			printf("#%d 0\n", k + 1);

	}

	return 0;
}