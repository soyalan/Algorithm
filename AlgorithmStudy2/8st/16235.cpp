#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int add[10][10];
int map[10][10];
int dead[10][10];
int baby[10][10];
vector<int> tree[10][10];

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			int s = 0, siz = tree[i][j].size();
			for (; s < siz; s++) {
				if (map[i][j] >= tree[i][j][s]) {
					map[i][j] -= tree[i][j][s];
					tree[i][j][s] += 1;
					if (tree[i][j][s] % 5 == 0) baby[i][j] += 1;
				}
				else break;
			}
			for (int k = siz - 1; k >= s; k--) {
				dead[i][j] += (tree[i][j][k] / 2);
				tree[i][j].pop_back();
			}
		}
	}
}

void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += dead[i][j];
			dead[i][j] = 0;
		}
	}
}

int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			for (int k = 0; k < baby[i][j]; k++) {
				for (int d = 0; d < 8; d++) {
					int y = i + dy[d];
					int x = j + dx[d];
					if (y >= 0 && y < N && x >= 0 && x < N) {
						tree[y][x].push_back(1);
					}
				}
			}
			baby[i][j] = 0;
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += add[i][j];
		}
	}
}

int main() {
	int M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 5;
			cin >> add[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> y >> x >> z;
		tree[y - 1][x - 1].push_back(z);
	}

	for (int k = 0; k < K; k++) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) sort(tree[i][j].begin(), tree[i][j].end());
		spring();
		summer();
		fall();
		winter();
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res += tree[i][j].size();
		}
	}

	cout << res << "\n";

	return 0;
}