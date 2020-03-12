#include <iostream>

using namespace std;

int n, m;
int item[101];
int map[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) cin >> item[i];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) map[i][j] = 100000000;
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		map[a][b] = l;
		map[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if(map[i][j] <= m) sum += item[j];
		}
		if (sum > res) res = sum;
	}

	cout << res << "\n";

	return 0;
}