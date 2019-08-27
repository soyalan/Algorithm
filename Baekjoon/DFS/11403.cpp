#include <stdio.h>
#include <iostream>

using namespace std;

int arr[100][100];
int way[100][100];
bool visitied[100][100];
int n;
int top;

void dfs(int y) {
	for (int i = 0; i < n; i++) {
		if (arr[y][i] == 0) continue;
		if (visitied[top][i]) continue;
		way[top][i] = 1;
		visitied[top][i] = true;
		dfs(i);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (top = 0; top < n; top++) {
		dfs(top);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", way[i][j]);
		}
		printf("\n");
	}

	return 0;
}
