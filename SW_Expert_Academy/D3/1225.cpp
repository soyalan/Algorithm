#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	for (int k = 0; k < 10; k++) {
		int num;
		cin >> num;
		queue<int> q;
		for (int i = 0; i < 8; i++) {
			int n;
			cin >> n;
			q.push(n);
		}
		int cnt = 1;
		int number;
		while (1) {
			number = q.front();
			q.pop();
			number -= cnt++;
			if (cnt == 6)cnt = 1;

			if (number > 0)q.push(number);
			else {
				q.push(0);
				break;
			}
		}
		printf("#%d ", k + 1);
		for (int i = 0; i < 8; i++) {
			number = q.front();
			q.pop();
			printf("%d ", number);
		}
		printf("\n");

	}



	return 0;
}