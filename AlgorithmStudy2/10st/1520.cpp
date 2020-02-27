#include <iostream>

using namespace std;

int height, width;
int map[500][500];
int dp[500][500];

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int dfs(int y, int x) {
	if (y == height - 1 && x == width - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
			if (map[y][x] > map[ny][nx]) {
				dp[y][x] += dfs(ny, nx);
			}
		}
	}
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0) << "\n";

	return 0;
}