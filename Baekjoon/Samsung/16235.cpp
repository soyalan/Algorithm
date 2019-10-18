#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int map[11][11];
int rice[11][11];
int wrice[11][11];
int add[11][11];
vector<int> tree[11][11];

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int siz = tree[i][j].size();
			if(siz > 0 ) sort(tree[i][j].begin(), tree[i][j].end());
			int cnt = 0;
			for (int s = 0; s < siz - cnt; s++) {
				int cur = tree[i][j][s];
				if (map[i][j] >= cur) {
					map[i][j] -= cur;
					tree[i][j][s] = cur + 1;
					if (tree[i][j][s] % 5 == 0) add[i][j]++;
				}
				else {
					tree[i][j].erase(tree[i][j].begin() + s);
					rice[i][j] += (cur / 2);
					s--;
					cnt++;
				}
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
						tree[y][x].push_back(1);
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

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int s;
			scanf(" %d", &s);
			map[i][j] = 5;
			wrice[i][j] = s;
		}
	}

	for (int i = 0; i < M; i++) {
		int y, x, z;
		scanf(" %d %d %d", &y, &x, &z);
		tree[y - 1][x - 1].push_back(z);
	}
	for (int year = 1; year <= K; year++) {
		spring();
		summer();
		fall();
		winter();
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