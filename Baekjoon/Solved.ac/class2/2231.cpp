#include <iostream>

using namespace std;

int check(int n) {
	int tmp = n;
	while (n > 0) {
		tmp += n % 10;
		n /= 10;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int num = 1;
	bool flag = false;
	for (; num <= 1000000; num++) {
		if (check(num) == n) {
			flag = true;
			break;
		}
	}

	if (flag) cout << num << "\n";
	else cout << "0\n";

	return 0;
}