#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void tree(int** map, int N, int y, int x) {
	bool check = true;
	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			if (map[i][j] != map[y][x]) check = false;
		}
	}
	if (check) {
		cout << map[y][x];
	}
	else {
		cout << "(";
		int n = N / 2;
		tree(map, n, y, x);
		tree(map, n, y, x + n);
		tree(map, n, y + n, x);
		tree(map, n, y + n, x + n);
		cout << ")";
	}
}

int main() {

	int N;
	cin >> N;
	int** map = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) map[i] = (int*)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%1d", &map[i][j]);
	
	tree(map, N, 0, 0);
	cout << "\n";


	for (int i = 0; i < N; i++) free(map[i]);
	free(map);

	return 0;
}