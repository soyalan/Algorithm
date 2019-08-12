#include <stdio.h>
#include <iostream>

int arr[100][2];
bool visited[100];
bool B = false;

void dfs(int start) {
	if (B) return;
	if (visited[start]) return;
	visited[start] = true;
	for (int i = 0; i < 2; i++) {
		if (arr[start][i]) {
			int x = arr[start][i];
			if (x == 99)
				B = true;
			dfs(x);
		}
	}
}

int main() {

	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 100; i++) {
			arr[i][0] = 0;
			arr[i][1] = 0;
			visited[i] = false;
		}
		B = false;
		int t, n;
		scanf("%d %d ", &t, &n);
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d ", &a, &b);
			if (arr[a][0]) {
				arr[a][1] = b;
			}
			else {
				arr[a][0] = b;
			}
		}

		dfs(0);
		if (B) 
			printf("#%d 1\n", k + 1);
		else 
			printf("#%d 0\n", k + 1);
	}


	return 0;
}