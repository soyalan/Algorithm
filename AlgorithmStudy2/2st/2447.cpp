#include <iostream>
#include <stdlib.h>

using namespace std;

char** map;

int dy[] = { 0,0,0,1,1,2,2,2 };
int dx[] = { 0,1,2,0,2,0,1,2 };

void star(int N, int y, int x) {
	if (N == 3) {
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			map[ny][nx] = '*';
		}
	}
	else {
		int n = N / 3;
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i] * n;
			int nx = x + dx[i] * n;
			star(n, ny, nx);
		}
	}
}

int main() {

	int N;
	cin >> N;
	map = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) map[i] = (char*)malloc(sizeof(char*) * N);;
	
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) map[i][j] = ' ';
		
	star(N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < N; i++) free(map[i]);
	free(map);

	return 0;
}