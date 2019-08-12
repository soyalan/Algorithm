#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool Dvisited[1001];
bool Bvisited[1001];
vector <int> arr[1001];

void dfs(int x) {
	if (Dvisited[x]) return;
	Dvisited[x] = true;
	printf("%d ", x);
	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	Bvisited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];
			if (!Bvisited[y]) {
				q.push(y);
				Bvisited[y] = true;
			}
		}
	}
}

int main() {

	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	dfs(v);
	printf("\n");
	bfs(v);
	printf("\n");

	return 0;
}