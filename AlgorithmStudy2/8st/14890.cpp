#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;
	int map[100][100];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];

	int res = 0;
	// ->
	for (int j = 0; j < N; j++) {
		int bef = map[0][j], cnt = 1;
		bool check = true;
		
		for (int i = 1; i < N; i++) {
			int cur = map[i][j];
			if (bef == cur) {
				cnt++;
			}
			else if (bef + 1 == cur) {
				if (cnt >= L) {
					cnt = 1;
					bef = map[i][j];
				}
				else {
					check = false;
					break;
				}
			}
			else if (bef == cur + 1) {
				cnt = 0;
				if (i + L > N) {
					check = false;
					break;
				}
				else {
					for (int k = 1; k < L; k++) {
						i++;
						if (map[i][j] != cur) check = false;
					}
					if (!check) break;
					bef = map[i][j];
				}
			}
			else {
				check = false;
				break;
			}

		}
		if (check) res++;
	}

	for (int i = 0; i < N; i++) {
		int bef = map[i][0], cnt = 1;
		bool check = true;

		for (int j = 1; j < N; j++) {
			int cur = map[i][j];
			if (bef == cur) {
				cnt++;
			}
			else if (bef + 1 == cur) {
				if (cnt >= L) {
					cnt = 1;
					bef = map[i][j];
				}
				else {
					check = false;
					break;
				}
			}
			else if (bef == cur + 1) {
				cnt = 0;
				if (j + L > N) {
					check = false;
					break;
				}
				else {
					for (int k = 1; k < L; k++) {
						j++;
						if (map[i][j] != cur) check = false;
					}
					if (!check) break;
					bef = map[i][j];
				}
			}
			else {
				check = false;
				break;
			}

		}
		if (check) res++;
	}

	cout << res << "\n";

}