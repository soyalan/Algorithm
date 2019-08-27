#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int n;
		cin >> n;
		int number = n;
		bool ten[10] = { false };
		int cnt = 0;
		int result = 0;
		while (1) {
			while (number > 0) {
				int a = number % 10;
				number /= 10;
				if (!ten[a]) {
					ten[a] = true;
					cnt++;
				}
			}
			if (cnt == 10)break;
			result++;
			number = n * result;
		}
		printf("#%d %d\n", k + 1, n * result);

	}

	return 0;
}