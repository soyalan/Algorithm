#include <iostream>
#include <queue>

using namespace std;

int height, width;
char map[1000][1000];
queue<pair<int, int> > fire;
queue<pair<int, int> > sg;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int bfs() {

	int cnt = 1;
	while (!sg.empty()) {
		int siz = fire.size(), y, x;
		for (int s = 0; s < siz; s++) {
			y = fire.front().first;
			x = fire.front().second;
			fire.pop();
			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
					if (map[ny][nx] == '.' || map[ny][nx] == '@') {
						fire.push({ ny,nx });
						map[ny][nx] = '*';
					}
				}
			}
		}

		siz = sg.size();
		for (int s = 0; s < siz; s++) {
			y = sg.front().first;
			x = sg.front().second;
			sg.pop();
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
				return cnt;
			}
			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
					if (map[ny][nx] == '.') {
						sg.push({ ny,nx });
						map[ny][nx] = '@';
					}
				}
			}
		}
		cnt++;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> width >> height;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') sg.push({ i,j });
				else if (map[i][j] == '*') fire.push({ i,j });
			}
		}

		int res = bfs();

		if (res > 0) cout << res << "\n";
		else cout << "IMPOSSIBLE\n";

		while (!sg.empty()) sg.pop();
		while (!fire.empty()) fire.pop();
	}


	return 0;
}