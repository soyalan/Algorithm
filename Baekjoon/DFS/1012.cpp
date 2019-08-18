#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int width, height;
int arr[50][50];
bool visitied[50][50];
int cnt;

void dfs(int y, int x) {
	if (visitied[y][x]) return;
	visitied[y][x] = true;
	if (!arr[y][x]) return;

	if (x > 0)
		dfs(y, x - 1);
	if (x < width)
		dfs(y, x + 1);
	if (y > 0)
		dfs(y - 1, x);
	if (y < height)
		dfs(y + 1, x);
}

int main() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		int number = 0;
		cin >> width >> height >> number;
		cout << "init. " << width << " " << height << " " << number << endl;
		// ÃÊ±âÈ­
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				arr[i][j] = 0;
				visitied[i][j] = false;
			}
		}
		cnt = 0;
		for (int i = 0; i < number; i++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (!visitied[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		 
		cout << "----- " << cnt << endl;

	}

	return 0;
}