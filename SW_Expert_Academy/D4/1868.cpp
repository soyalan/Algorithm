#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N;
int map[301][301];
bool visited[301][301];
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };


void bfs(int sy, int sx) {
	queue<pair<int, int> > q;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x]) continue;
		visited[y][x] = true;
		int boom = 0;
		for (int d = 0; d < 8; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[ny][nx] == -2) boom++;
			}
		}
		map[y][x] = boom;
		if (boom == 0) {
			for (int d = 0; d < 8; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		char a;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %c", &a);
				if (a == '.') map[i][j] = -1;
				else map[i][j] = -2;
				visited[i][j] = false;
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == -1) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		printf("#%d %d\n", t, cnt);
	}



	return 0;
}