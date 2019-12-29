#include <iostream>
#include <stdlib.h>

using namespace std;

void dfs(int* arr, int N, int M, int i, int cnt) {
	if (cnt == M) {
		for (int j = 0; j < M; j++) cout << arr[j] << " ";
		cout << "\n";
		return;
	}

	for (int j = i; j <= N; j++) {
		arr[cnt] = j;
		dfs(arr, N, M, j, cnt + 1);
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	int* arr = (int*)malloc(sizeof(int) * M);

	dfs(arr, N, M, 1, 0);

	free(arr);

	return 0;
}