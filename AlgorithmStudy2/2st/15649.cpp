#include <iostream>
#include <stdlib.h>

using namespace std;

void dfs(int* arr, bool* visited, int N, int M, int cnt) {
	if (M == cnt) {
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(arr, visited, N, M, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	int* arr = (int*)malloc(sizeof(int) * M);
	bool* visited = (bool*)malloc(sizeof(bool) * (N + 1));
	for (int i = 0; i <= N; i++) visited[i] = false;

	dfs(arr, visited, N, M, 0);
	
	free(arr);
	free(visited);

	return 0;
}