#include <iostream>
#include <stdlib.h>

using namespace std;

char** map;

int dy1[] = { 0, 1, 1, 2, 2, 2, 2, 2 };
int dx1[] = { 2, 1, 3, 0, 1, 2, 3, 4 };

void tree(int N, int y, int x) {
	if (N == 6) {
		for (int i = 0; i < 8; i++) {
			int ny = y + dy1[i];
			int nx = x + dx1[i];
			map[ny][nx] = '*';
		}
	}
	else {
		int n = N / 2;
		tree(n, y, x + n / 2);
		tree(n, y + n / 2, x);
		tree(n, y + n / 2, x + n);
	}
}

int main() {

	int N;
	cin >> N;
	map = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) map[i] = (char*)malloc(sizeof(char*) * N * 2);
	for (int i = 0; i < N; i++) for (int j = 0; j < N * 2; j++) map[i][j] = ' ';

	tree(N * 2, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < N; i++) free(map[i]);
	free(map);

	return 0;
}