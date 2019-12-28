#include <iostream>

using namespace std;

int r, c, res;

int dy[] = { 0,0,1,1 };
int dx[] = { 0,1,0,1 };

void div(int cnt, int N, int y, int x) {
	if (N == 2) {
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny == r && nx == c) res = cnt;
			cnt++;
		}
	}
	else {
		int ny = y + (N / 2);
		int nx = x + (N / 2);
		if(r < ny && c < nx) div(cnt, N / 2, y, x);
		else if(r < ny && c >= nx) div(cnt + ((N / 2) * (N / 2)), N / 2, y, nx);
		else if (r >= ny && c < nx) div(cnt + ((N / 2) * (N / 2)) * 2, N / 2, ny, x);
		else if (r >= ny && c >= nx) div(cnt + ((N / 2) * (N / 2)) * 3, N / 2, ny, nx);
	}

}

int main() {
	int n;
	cin >> n >> r >> c;
	int N = 1 << n;

	div(0, N, 0, 0);

	cout << res << "\n";

	return 0;
}