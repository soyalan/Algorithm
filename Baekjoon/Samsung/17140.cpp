#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

class D {
public:
	int number, cnt;
};

int A[101][101];
D arr[101];
int r, c, k;
int width = 3, height = 3;

bool compare(D a, D b) {
	if (a.cnt == b.cnt)
		return a.number > b.number;
	else
		return a.cnt > b.cnt;
}

void clean() {
	for (int i = 0; i < 101; i++) {
		arr[i].number = 0;
		arr[i].cnt = 0;
	}
}

void R() {
	int i, j, num, cnt, max = 0;
	for (i = 0; i < height; i++) {
		cnt = 0;
		for (j = 0; j < width; j++) {
			num = A[i][j];
			if (num == 0)continue;
			if (!arr[num].cnt) {
				arr[num].number = num;
				cnt++;
			}
			arr[num].cnt += 1;
		}

		sort(arr, arr + 101, compare);

		int k = 0;
		for (j = cnt - 1; j >= 0; j--) {
			A[i][k++] = arr[j].number;
			A[i][k++] = arr[j].cnt;
			if (k > 100)break;
		}
		for (j = cnt * 2; j < 101; j++) {
			A[i][j] = 0;
		}
		if (cnt > max)max = cnt;
		clean();
	}
	width = max * 2;
}

void C() {
	int i, j, num, cnt, max = 0;
	for (i = 0; i < width; i++) {
		cnt = 0;
		for (j = 0; j < height; j++) {
			num = A[j][i];
			if (num == 0)continue;
			if (!arr[num].cnt) {
				arr[num].number = num;
				cnt++;
			}
			arr[num].cnt += 1;
		}

		sort(arr, arr + 101, compare);

		int k = 0;
		for (j = cnt - 1; j >= 0; j--) {
			A[k++][i] = arr[j].number;
			A[k++][i] = arr[j].cnt;
			if (k > 100)break;
		}
		for (j = cnt * 2; j < 101; j++) {
			A[j][i] = 0;
		}
		if (cnt > max)max = cnt;
		clean();
	}
	height = max * 2;
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	int cnt = 0;
	clean();
	while (A[r-1][c-1] != k) {
		if (height >= width) {
			R();
		}
		else {
			C();
		}
		cnt++;
		if (cnt > 100) break;
	}

	if (cnt > 100) cnt = -1;
	
	printf("%d\n", cnt);
	return 0;
}