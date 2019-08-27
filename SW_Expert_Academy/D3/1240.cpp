#include <stdio.h>
#include <iostream>

using namespace std;

int arr[51][101];
int pw[56];

int check() {
	int num[8];
	int number = 0;
	int cnt = 0;

	for (int i = 0; i <= 56; i++) {
		if (i % 7 == 0 && i != 0) {
			if (number == 13) num[cnt++] = 0;
			else if (number == 25) num[cnt++] = 1;
			else if (number == 19) num[cnt++] = 2;
			else if (number == 61) num[cnt++] = 3;
			else if (number == 35) num[cnt++] = 4;
			else if (number == 49) num[cnt++] = 5;
			else if (number == 47) num[cnt++] = 6;
			else if (number == 59) num[cnt++] = 7;
			else if (number == 55) num[cnt++] = 8;
			else if (number == 11) num[cnt++] = 9;
			else {
				return 0;
			}
			number = 0;
		}
		else {
			number = (number << 1) | pw[i];
		}
	}
	int result = 0;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) result += (num[i] * 3);
		else result += num[i];
		sum += num[i];
	}
	if (result % 10 == 0) return sum;
	else return 0;
}

int main() {
	int N, M, n;
	cin >> n;
	for (int k = 0; k < 10; k++) {
		cin >> N;
		cin >> M;
		int x = 0, y;
		bool one = false;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%1d", &arr[i][j]);
				if (arr[i][j] == 1 && x == 0) {
					y = i;
					x = j;
				}
			}
		}
		
		for (int i = 0; i < 56; i++) {
			if (arr[y][x + 55 - i] == 1) {
				cnt = i;
				break;
			}
		}
		int result = 0;
		for (int j = 0; j <= cnt; j++) {
			for (int i = 0; i < 56; i++) {
				pw[i] = arr[y][x + i - j];
			}
			result = check();
			if (result) break;
		}

		printf("#%d %d\n", k + 1, result);

	}

	return 0;
}