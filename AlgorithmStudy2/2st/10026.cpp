#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void bfs(char** map, bool** visited, int N, int i, int j) {
	queue<pair<int, int> > q;
	q.push({ i,j });
	char a = map[i][j];
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x]) continue;
		visited[y][x] = true;
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (map[ny][nx] == a && !visited[ny][nx]) {
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	char** map = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) map[i] = (char*)malloc(sizeof(char) * N);

	bool** visited = (bool**)malloc(sizeof(bool*) * N);
	for (int i = 0; i < N; i++) visited[i] = (bool*)malloc(sizeof(bool) * N);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visited[i][j] = false;
		}
	}

	int normal = 0, redGreen = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(map, visited, N, i, j);
				normal++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(map, visited, N, i, j);
				redGreen++;
			}
		}
	}

	cout << normal << " " << redGreen << "\n";

	for (int i = 0; i < N; i++) free(map[i]);
	free(map);
	for (int i = 0; i < N; i++) free(visited[i]);
	free(visited);

	return 0;
}