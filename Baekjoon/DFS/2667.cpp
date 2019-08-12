#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26][26];
bool visited[26][26];
vector<int> v;
int cnt;
int n;

void dfs(int x, int y) {
	if (visited[x][y]) return;
	visited[x][y] = true;
	if (!arr[x][y]) return;
	cnt++;

	if (x > 0) {
		if (arr[x - 1][y] == 1)
			dfs(x - 1, y);
	}
	if (x < n - 1) {
		if (arr[x + 1][y] == 1)
			dfs(x + 1, y);
	}
	if (y > 0) {
		if (arr[x][y - 1] == 1)
			dfs(x, y - 1);
	}
	if (y < n - 1) {
		if (arr[x][y + 1] == 1)
			dfs(x, y + 1);
	}

}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 0;
			dfs(i, j);
			if(cnt)
				v.push_back(cnt);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}