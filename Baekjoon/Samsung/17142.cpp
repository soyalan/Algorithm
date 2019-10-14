#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[51][51];
int N, M;
vector<pair<int, int> > virus;
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void copy(int arr[51][51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = map[i][j];
		}
	}
}

int bfs(vector<int> v, int count) {
	int arr[51][51];
	copy(arr);
	queue<pair<pair<int, int>, int> > q;
	int cnt = 0;
	for (int i = 0; i < M; i++) q.push({ {virus[v[i]].first,virus[v[i]].second }, cnt });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		if (arr[y][x] == 3)continue;
		if (arr[y][x] == 0) count--;
		arr[y][x] = 3;
		if (count == 0)break;
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (arr[ny][nx] == 0) {
					q.push({ {ny,nx}, cnt + 1 });
				}
				else if (arr[ny][nx] == 2) {
					if (count == 0) q.push({ {ny,nx}, cnt });
					else q.push({ {ny,nx}, cnt + 1 });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) return -1;
		}
	}

	return cnt;
}

int main() {
	cin >> N >> M;
	int vcount = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
				vcount++;
			}
			else if (map[i][j] == 0) count++;
		}
	}
	int per[11] = { 0 };
	for (int i = 0; i < M; i++) per[i] = 1;
	sort(per, per + vcount);

	int min = 1000000000;
	bool check = false;
	do {
		vector<int> v;
		for (int i = 0; i < vcount; i++) {
			if (per[i])	v.push_back(i);
		}
		
		int cnt = bfs(v, count);

		if (cnt != -1) {
			check = true;
			if (min > cnt) min = cnt;
		}

	} while (next_permutation(per, per + vcount));

	if (check) printf("%d\n", min);
	else printf("-1\n");

	return 0;
}