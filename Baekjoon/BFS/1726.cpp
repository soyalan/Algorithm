#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int height, width;
int map[101][101];
int visited[101][101];
int boty, botx, botd;
int toy, tox, tod;
int dy[] = { 0,0,0,1,-1 };
int dx[] = { 0,1,-1,0,0 };

int bfs() {
	int min = 100000000;
	queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push({ { boty, botx }, { botd, 0 } });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (y == toy && x == tox) {
			if (tod == 1) {
				if (dir == 3 || dir == 4) cnt += 1;
				else if (dir == 2) cnt += 2;
			}
			else if (tod == 2) {
				if (dir == 3 || dir == 4) cnt += 1;
				else if (dir == 1) cnt += 2;
			}
			else if (tod == 3) {
				if (dir == 1 || dir == 2) cnt += 1;
				else if (dir == 4) cnt += 2;
			}
			else {
				if (dir == 1 || dir == 2) cnt += 1;
				else if (dir == 3) cnt += 2;
			}
			if (min > cnt)min = cnt;
			continue;
		}

		if (cnt > min) continue;
		if (visited[y][x] != 0 && visited[y][x] >= cnt) continue;
		visited[y][x] = cnt;
		printf("(%d %d) %d %d\n", y, x, dir, cnt);
		
		for (int i = 1; i <= 4; i++) {
			int tx, ty;
			for (int j = 1; j < 4; j++) {
				ty = y + dy[i] * j;
				tx = x + dx[i] * j;
				if (tx >= 0 && tx < width && ty >= 0 && ty < height) {
					if (j == 1 && map[ty][tx] == 1) break;
					if (map[ty][tx] == 0) {
						if (dir == 1) {
							if (i == 1) q.push({ {ty,tx},{i, cnt + 1} });
							else if (i == 3 || i == 4) q.push({ {ty,tx},{i, cnt + 2} });
						}
						else if (dir == 2) {
							if (i == 2) q.push({ {ty,tx},{i, cnt + 1} });
							else if (i == 3 || i == 4) q.push({ {ty,tx},{i, cnt + 2} });
						}
						else if (dir == 3) {
							if (i == 3) q.push({ {ty,tx},{i, cnt + 1} });
							else if (i == 1 || i == 2) q.push({ {ty,tx},{i, cnt + 2} });
						}
						else {
							if (i == 4) q.push({ {ty,tx},{i, cnt + 1} });
							else if (i == 1 || i == 2) q.push({ {ty,tx},{i, cnt + 2} });
						}
					}
				}
			}
		}
	}

	return min;
}

int main() {
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}

	cin >> boty >> botx >> botd;
	cin >> toy >> tox >> tod;

	boty--;
	botx--;
	toy--;
	tox--;

	printf("%d\n", bfs());

	return 0;
}