#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

void bfs(int* arr, int N, vector<vector<int> >& v) {
	queue<int> line;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) line.push(i);
	}
	while (!line.empty()) {
		int n = line.front();
		line.pop();
		cout << n << "\n";
		while (!v[n].empty()) {
			int temp = v[n].back();
			v[n].pop_back();
			arr[temp]--;
			if (arr[temp] == 0) line.push(temp);
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int* arr = (int*)malloc(sizeof(int) * (N + 1));
	for (int i = 0; i <= N; i++) arr[i] = 0;
	vector<vector<int> > v(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}

	bfs(arr, N, v);

	free(arr);

	return 0;
}