#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int map[11][11];
int rice[11][11];
int wrice[11][11];
int add[11][11];
priority_queue<int> tree[11][11];

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			queue<int> q;
			int siz = tree[i][j].size();
			for (int s = 0; s < siz; s++) {
				int cur = tree[i][j].top();
				tree[i][j].pop();
				if (map[i][j] >= cur) {
					map[i][j] -= cur;
					q.push(cur + 1);
				}
				else {
					rice[i][j] += (cur / 2);
				}
			}
			siz = q.size();
			for (int s = 0; s < siz; s++) {
				tree[i][j].push(q.front());
				if (q.front() % 5 == 0) add[i][j]++;
				q.pop();
			}
		}
	}
}

void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += rice[i][j];
			rice[i][j] = 0;
		}
	}
}

void fall() {
	int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int s = 0; s < add[i][j]; s++) {
				for (int d = 0; d < 8; d++) {
					int y = i + dy[d];
					int x = j + dx[d];
					if (x >= 0 && x < N && y >= 0 && y < N) {
						tree[y][x].push(1);
					}
				}
			}
			add[i][j] = 0;
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += wrice[i][j];
		}
	}
}

void print(int y) {
	printf("========== %d ==========\n", y);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", tree[i][j].size());
		}
		printf("\n");
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int s;
			cin >> s;
			map[i][j] = 5;
			wrice[i][j] = s;
		}
	}

	for (int i = 0; i < M; i++) {
		int y, x, z;
		cin >> y >> x >> z;
		tree[y - 1][x - 1].push(z);
	}
	print(0);
	for (int year = 1; year <= K; year++) {
		spring();
		summer();
		fall();
		winter();
		print(year);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt += tree[i][j].size();
		}
	}
	printf("%d\n", cnt);
	return 0;
}