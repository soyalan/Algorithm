#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int height, width;
int map[1001][1001];
bool visited[1001][1001];
queue < pair<pair<int, int>, int> > fire;
queue < pair<pair<int, int>, int> > jihun;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs() {
	int time = 0;
	while (!jihun.empty()) {
		while (jihun.front().second == time) {
			int y = jihun.front().first.first;
			int x = jihun.front().first.second;
			int cnt = jihun.front().second;
			jihun.pop();
			if (map[y][x] == 3) {
				if (jihun.empty()) break;
				else continue;
			}
			if ((y == 0 || y == height - 1 || x == 0 || x == width - 1) && map[y][x] == 0) {
				return cnt + 1;
			}
			if (visited[y][x]) {
				if (jihun.empty()) break;
				else continue;
			}
			visited[y][x] = true;
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
					if (map[ny][nx] == 0) {
						jihun.push({ {ny,nx}, cnt + 1 });
					}
				}
			}
			if (jihun.empty()) break;
		}

		if (!fire.empty()) {
			while (fire.front().second == time) {
				int y = fire.front().first.first;
				int x = fire.front().first.second;
				int cnt = fire.front().second;
				fire.pop();
				for (int k = 0; k < 4; k++) {
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
						if (map[ny][nx] == 0) {
							fire.push({ {ny,nx}, cnt + 1 });
							map[ny][nx] = 3;
						}
					}
				}
				if (fire.empty())break;
			}
		}

		time++;
	}
	return -1;
}

int main() {
	cin >> height >> width;
	char a;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf(" %c", &a);
			if (a == '.') {
				map[i][j] = 0;
			}
			else if (a == '#') {
				map[i][j] = 1;
			}
			else if (a == 'J') {
				map[i][j] = 0;
				jihun.push({ {i,j}, 0 });
			}
			else if (a == 'F') {
				map[i][j] = 3;
				fire.push({ { i,j }, 0 });
			}
		}
	}

	int cnt = bfs();
	if (cnt == -1) printf("IMPOSSIBLE\n");
	else printf("%d\n", cnt);



	return 0;
}