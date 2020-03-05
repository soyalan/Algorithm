#include <iostream>

using namespace std;

long long arr[101];

void init() {
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6; i <= 100; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	init();
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		cout << arr[N] << "\n";
	}

	return 0;
}