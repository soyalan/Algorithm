#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

bool** vis(int N) {
	bool** visited = (bool**)malloc(sizeof(bool*) * N);
	for (int i = 0; i < N; i++) visited[i] = (bool*)malloc(sizeof(bool) * N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) visited[i][j] = false;
	return visited;
}

void visfree(bool** visited, int N) {
	for (int i = 0; i < N; i++) free(visited[i]);
	free(visited);
}

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

bool bfs(int** map, int N, int i, int j, bool** visited, int L, int R) {
	queue<pair<int, int> > q;
	vector<pair<int, int> > v;
	int sum = 0;
	q.push({ i,j });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x]) continue;
		visited[y][x] = true;
		v.push_back({ y,x });
		sum += map[y][x];
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				int gap = abs(map[y][x] - map[ny][nx]);
				if (gap >= L && gap <= R) q.push({ ny,nx });
			}
		}
	}

	int siz = v.size();
	if (siz > 1) {
		int temp = sum / siz;
		for (int i = 0; i < siz; i++) {
			map[v[i].first][v[i].second] = temp;
		}
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L, R;
	cin >> N >> L >> R;
	int** map = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) map[i] = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];
	
	bool flag = true;
	int cnt = 0;
	while (flag) {
		flag = false;
		bool** visited = vis(N);	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bool check = bfs(map, N, i, j, visited, L, R);
					if (check)flag = true;
				}
			}
		}
		if (flag)cnt++;
		visfree(visited, N);
	}

	cout << cnt << "\n";
	for (int i = 0; i < N; i++) free(map[i]);
	free(map);
	return 0;
}