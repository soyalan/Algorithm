#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Shark {
public:
	int x, y;
	int age, cnt;
};

int N;
int map[21][21];
Shark shark;
int fish[7];
bool check = true;

bool meal() {
	if (!check) return false;
	for (int i = 1; i < shark.age; i++) {
		if (fish[i]) return true;
	}
	return false;
}

bool compare(pair<int, int> a1, pair<int, int> a2) {
	if (a1.first == a2.first) return a1.second < a2.second;
	return a1.first < a2.first;
}

int eat() {
	check = false;
	queue<pair<pair<int, int>, int> > q;
	vector<pair<int, int> > v;
	bool visited[21][21] = { false };
	int dy[] = {-1, 0, 0, 1};
	int dx[] = {0, -1, 1, 0};
	int cnt = 0, min = 100000000;
	q.push({ { shark.y, shark.x }, cnt });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		if (map[y][x] < shark.age && map[y][x] != 0) {
			if (min > cnt) min = cnt;
			if (min == cnt) {
				v.push_back({ y,x });
				check = true;
			}
		}
		if (cnt > min) continue;
		if (visited[y][x]) continue;
		visited[y][x] = true;
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[ny][nx] <= shark.age) {
					q.push({ { ny, nx }, cnt + 1 });
				}
			}
		}
	}
	if (!check) return 0;
	sort(v.begin(), v.end(), compare);
	map[shark.y][shark.x] = 0;
	fish[map[v.front().first][v.front().second]]--;
	shark.y = v.front().first;
	shark.x = v.front().second;
	map[shark.y][shark.x] = 9;
	shark.cnt++;
	if (shark.age == shark.cnt) {
		shark.age++;
		if (shark.age == 8) shark.age = 7;
		shark.cnt = 0;
	}
	return min;
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %d", &map[i][j]);
			if (map[i][j] == 9) {
				shark.y = i;
				shark.x = j;
				shark.age = 2;
				shark.cnt = 0;
			}
			else if (map[i][j]) {
				fish[map[i][j]]++;
			}
		}
	}

	int cnt = 0;
	while (meal()) {
		cnt += eat();
	}
	printf("%d\n", cnt);

	return 0;
}