#include <iostream>
#include <vector>

using namespace std;

int map[101][101];

int main() {

	int N;
	cin >> N;
	for (int n = 0; n < N; n++) {
		int x, y, d, g, siz;
		cin >> x >> y >> d >> g;
		vector<int> v;
		v.push_back(d);
		// 0 right, 1 up, 2 left, 3 down
		for (int m = 0; m < g; m++) {
			siz = v.size();
			for (int i = siz - 1; i >= 0; i--) {
				int cur = v[i] + 1;
				if (cur == 4) cur = 0;
				v.push_back(cur);
			}
		}
		siz = v.size();
		map[y][x] = 1;
		for (int i = 0; i < siz; i++) {
			if (v[i] == 0) x++;
			else if (v[i] == 1) y--;
			else if (v[i] == 2) x--;
			else y++;
			if (x >= 0 && x <= 100 && y >= 0 && y <= 100) map[y][x] = 1;
		} 
	}

	int res = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) res++;
		}
	}

	cout << res << "\n";

	return 0;
}