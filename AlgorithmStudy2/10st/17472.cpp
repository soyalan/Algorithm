#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int height, width;
int map[100][100];
int arr[7][7];
vector<pair<pair<int, int>, int> > line;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void numbering(int i, int j, int n) {
	map[i][j] = n;
	for (int d = 0; d < 4; d++) {
		int y = i + dy[d];
		int x = j + dx[d];
		if (x >= 0 && x < width && y >= 0 && y < height) {
			if (map[y][x] == -1) numbering(y, x, n);
		}
	}
}

void lining2(int y, int x, int d, int n, int cnt) {
	if (map[y][x] != 0) {
		int m = map[y][x];
		if (cnt < 2) return;
		if (arr[n][m] == 0) arr[n][m] = cnt;
		else arr[n][m] = min(arr[n][m], cnt);
		return;
	}
	int ny = y + dy[d];
	int nx = x + dx[d];
	if (nx >= 0 && nx < width && ny >= 0 && ny < height) lining2(ny, nx, d, n, cnt + 1);
}

void lining(int y, int x) {
	int n = map[y][x];
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
			if (map[ny][nx] != n) lining2(ny, nx, d, n, 0);
		}
	}
}

bool op(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.second == b.second) return a.first.first < b.first.first;
	else return a.second < b.second;
}

int uni[7];

int getP(int n) {
	if (n == uni[n]) return n;
	else return uni[n] = getP(uni[n]);
}

void uniP(int a, int b) {
	a = getP(a);
	b = getP(b);
	if (a < b) uni[b] = a;
	else uni[a] = b;
}

int connect(int cnt) {
	for (int i = 1; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (arr[i][j]) line.push_back({ {i,j}, arr[i][j] });
		}
	}

	sort(line.begin(), line.end(), op);
	for (int i = 1; i < cnt; i++) uni[i] = i;

	int siz = line.size(), res = 0;
	for (int i = 0; i < siz; i++) {
		if (getP(line[i].first.first) != getP(line[i].first.second)) {
			uniP(line[i].first.first, line[i].first.second);
			res += line[i].second;
		}
	}

	int n = uni[1];
	for (int i = 2; i < cnt; i++) if (getP(uni[i]) != n) return -1;

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}

	int cnt = 1;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j] == -1) {
				numbering(i, j, cnt);
				cnt++;
			}
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j]) {
				lining(i, j);
			 }
		}
	}

	cout << connect(cnt) << "\n";

	return 0;
}