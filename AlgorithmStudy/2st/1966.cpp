#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		queue<pair<int, int> > q;
		vector<int> check;
		int N, M, n;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> n;
			q.push(pair<int, int>(i, n));
			check.push_back(n);
		}
		sort(check.begin(), check.end(), compare);

		int cnt = 0;
		int c = 0;
		while (!q.empty()) {
			pair<int, int> k = q.front();
			q.pop();
			
			if (check[c] == k.second) {
				cnt++;
				c++;
				if (M == k.first) {
					printf("%d\n", cnt);
					break;
				}
			}
			else {
				q.push(k);
			}
		}

	}



	return 0;
}