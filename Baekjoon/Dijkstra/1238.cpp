/*
#include <stdio.h>
#include <iostream>

#define INF 100000000

using namespace std;

int N;
int arr[1001][1001] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floyd() {

	int pass[1001][1001];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			pass[i][j] = arr[i][j];
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (pass[i][k] + pass[k][j] < pass[i][j]) {
					pass[i][j] = pass[i][k] + pass[k][j];
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", pass[i][j]);
		}
		printf("\n");
	}
}

int main() {
	N = 4;

	floyd();

	return 0;
}
*/