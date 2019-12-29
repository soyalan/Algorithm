#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int bfs(char** map, int height, int width, int starty, int startx, vector<pair<int, int> >& Fire) {
	queue<pair<pair<int, int>, int > > run;
	queue<pair<pair<int, int>, int > > fire;
	run.push({ {starty, startx}, 0 });
	int fireSize = Fire.size();
	for (int i = 0; i < fireSize; i++) fire.push({ {Fire[i].first,Fire[i].second},0 });
	
	while (!run.empty()) {
		int cnt = run.front().second;
		while (!fire.empty()) {
			int y = fire.front().first.first;
			int x = fire.front().first.second;
			int cnt2 = fire.front().second;
			if (cnt != cnt2) break;
			fire.pop();
			map[y][x] = '*';
 			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
					if (map[ny][nx] == '.' || map[ny][nx] == '@') {
						fire.push({ {ny,nx}, cnt2 + 1 });
					}
				}
			}
		}

		int y = run.front().first.first;
		int x = run.front().first.second;
		run.pop();
		if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
			if (map[y][x] == '.' || map[y][x] == '@') {
				return cnt + 1;
			}
		}
		if (map[y][x] == '*') continue;
		map[y][x] = '@';
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
				if (map[ny][nx] == '.') {
					run.push({ {ny,nx}, cnt + 1 });
				}
			}
		}
	}

 	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int width, height;
		cin >> width >> height;

		char** map = (char**)malloc(sizeof(char*) * height);
		for (int i = 0; i < height; i++) map[i] = (char*)malloc(sizeof(char) * width);
		int starty, startx;
		vector<pair<int, int> > fire;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					starty = i;
					startx = j;
				}
				if (map[i][j] == '*') {
					fire.push_back({ i,j });
				}
			}
		}

		int res = bfs(map, height, width, starty, startx, fire);
		if (res == -1) cout << "IMPOSSIBLE\n";
		else cout << res << "\n";

		for (int i = 0; i < height; i++) free(map[i]);
		free(map);
	}

	return 0;
}