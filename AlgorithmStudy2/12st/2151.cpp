#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
char map[50][50];
vector<pair<int, int> > door;

// left, right, up, down
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int bfs() {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	for (int d = 0; d < 4; d++) {
		int ny = door[0].first + dy[d];
		int nx = door[0].second + dx[d];
		if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
			if (map[ny][nx] != '*') q.push({ {ny, nx},{d, 0} });
		}
	}

	int check[50][50];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) check[i][j] = -1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (y == door[0].first && x == door[0].second) continue;
		if ((map[y][x] == '!' || map[y][x] == '#') && check[y][x] != -1 && check[y][x] < cnt) continue;
		check[y][x] = cnt;

		if (map[y][x] == '.') {
			while (map[y][x] == '.') {
				y += dy[dir];
				x += dx[dir];
			}
			if (map[y][x] == '!' || map[y][x] == '#') q.push({ {y,x}, {dir, cnt} });
		}
		else if (map[y][x] == '!') {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (map[ny][nx] != '*') q.push({ {ny,nx},{dir, cnt} });
			}

			int tmp[2] = { 0 };
			if (dir == 0 || dir == 1) {
				tmp[0] = 2;
				tmp[1] = 3;
			}
			else if (dir == 2 || dir == 3) {
				tmp[0] = 0;
				tmp[1] = 1;
			}
			for (int d = 0; d < 2; d++) {
				ny = y + dy[tmp[d]];
				nx = x + dx[tmp[d]];
				if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
					if (map[ny][nx] != '*') q.push({ {ny,nx},{tmp[d], cnt + 1} });
				}
			}
		}
	}

	return check[door[1].first][door[1].second];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') door.push_back({ i,j });
		}
	}

	cout << bfs() << "\n";

	return 0;
}