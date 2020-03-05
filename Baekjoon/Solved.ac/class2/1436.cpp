#include <iostream>

using namespace std;

bool check(int n) {
	while (n > 100) {
		if (n % 1000 == 666) return true;
		n /= 10;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 666;; i++) {
		if (check(i)) cnt++;
		if (cnt == n) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}