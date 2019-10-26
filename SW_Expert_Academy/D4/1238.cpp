#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> v[101], int start) {
	bool visited[101] = { false };
	visited[start] = true;
	pair<int, int> res = { 0,0 };
	queue<pair<int, int> > q;
	q.push({ start, 0 });
	while (!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt > res.second) {
			res.first = n;
			res.second = cnt;
		}
		else if (cnt == res.second) {
			if (n >= res.first) {
				res.first = n;
			}
		}
		int siz = v[n].size();
		for (int i = 0; i < siz; i++) {
			if (!visited[v[n][i]]) {
				q.push({ v[n][i], cnt + 1 });
				visited[v[n][i]] = true;
			}
		}
	}

	return res.first;
}

int main() {
	for (int t = 1; t <= 1; t++) {
		int n, x;
		vector<int> v[101];
		scanf(" %d %d", &n, &x);
		for (int i = 0; i < n / 2; i++) {
			int a, b;
			scanf(" %d %d", &a, &b);
			v[a].push_back(b);
		}

		printf("#%d %d\n", t, bfs(v, x));
	}


	return 0;
}