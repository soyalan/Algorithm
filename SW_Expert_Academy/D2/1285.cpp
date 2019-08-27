#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int number;
	cin >> number;
	for (int k = 0; k < number; k++) {
		int n;
		cin >> n;
		int min = 100001;
		int dis;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			cin >> dis;
			dis = abs(dis);
			if (min >= dis) {
				min = dis;
				if (q.empty()) q.push(min);
				else if (q.front() > min) {
					while (q.front() > min) {
						q.pop();
						if (q.empty())break;
					}
					q.push(min);
				}
				else if (q.front() == min) {
					q.push(min);
				}
			}
		}
		printf("#%d %d %d\n", k + 1, q.front(), q.size());
		
	}

	return 0;
}