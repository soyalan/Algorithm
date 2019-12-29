#include <iostream>
#include <stdlib.h>

using namespace std;

int getParents(int* arr, int n) {
	if (arr[n] == n) return n;
	else return arr[n] = getParents(arr, arr[n]);
}

void makeUnion(int* arr, int a, int b) {
	if (arr[a] == arr[b]) return;
	a = getParents(arr, a);
	b = getParents(arr, b);
	if (a > b) arr[a] = b;
	if (a < b) arr[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int* arr = (int*)malloc(sizeof(int) * (N + 1));
	for (int i = 0; i <= N; i++) arr[i] = i;
	 
	for (int i = 0; i < M; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c) {
			if (getParents(arr, a) == getParents(arr, b)) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			makeUnion(arr, a, b);
		}
	}

	free(arr);

	return 0;
}