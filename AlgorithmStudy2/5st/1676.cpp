#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int cnt = N / 5;
	cnt += (N / 25);
	cnt += (N / 125);

	cout << cnt << "\n";

	return 0;
}