#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int bfs(int** map, int height, int width, int y, int x) {
	queue<pair<int, int> > q;
	int cnt = 1;
	q.push({ y,x });
	map[y][x] = 0;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = i + dy[d];
			int nx = j + dx[d];
			if (ny >= 0 && ny < height && nx >= 0 && nx < width){
				if (map[ny][nx]) {
					q.push({ ny,nx });
					map[ny][nx] = 0;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main() {

	int width, height;
	cin >> height >> width;
	int** map = (int**)malloc(sizeof(int*) * height);
	for (int i = 0; i < height; i++) {
		map[i] = (int*)malloc(sizeof(int) * width);
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}

	int max = 0, cnt = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j]) {
				int res = bfs(map, height, width, i, j);
				if (max < res)max = res;
				if (res > 0)cnt++;
			}
		}
	}

	cout << cnt << "\n" << max << "\n";

	for (int i = 0; i < height; i++) {
		free(map[i]);
	}
	free(map);

	return 0;
}