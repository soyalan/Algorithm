#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if ((a.first * a.second) == (b.first * b.second))
		return a.first < b.first;
	return (a.first * a.second) < (b.first * b.second);
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int n;
		int arr[100][100];
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		vector<pair<int, int>> v;
		int width, height, x, y;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j]) {
					width = 0;
					height = 0;
					x = j;
					y = i;
					while (arr[y][x]) {
						x++;
						width++;
						if (x == n)break;
					}
					while (arr[y][x - 1]) {
						y++;
						height++;
						if (y == n)break;
					}
					for (int w = i; w < y; w++) {
						for (int h = j; h < x; h++) {
							arr[w][h] = 0;
						}
					}
					v.push_back(pair<int, int>(height, width));
				}

			}
		}

		sort(v.begin(), v.end(), compare);

		vector<pair<int, int>>::iterator it = v.begin();
		printf("#%d %d ", k + 1, v.size());
		for (; it != v.end(); it++) {
			printf("%d %d ", it->first, it->second);
		}
		printf("\n");
	}

	return 0;
}