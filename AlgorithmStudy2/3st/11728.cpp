#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int K = N + M;

	int* A = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) cin >> A[i];
	int* B = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) cin >> B[i];
	int* res = (int*)malloc(sizeof(int) * K);

	int a = 0, b = 0, cnt = 0;
	while (cnt < K) {
		if (a < N && b < M) {
			if (A[a] < B[b]) {
				res[cnt++] = A[a++];
			}
			else {
				res[cnt++] = B[b++];
			}
		}
		else if (a == N && b < M) {
			res[cnt++] = B[b++];
		}
		else if (a < N && b == M) {
			res[cnt++] = A[a++];
		}
	}

	for (int i = 0; i < K; i++) cout << res[i] << " ";
	cout << "\n";

	free(A);
	free(B);
	free(res);

	return 0;
}