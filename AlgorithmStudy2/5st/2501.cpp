#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int n = 1;
	vector<int> v;
	while (N >= n) {
		if (N % n == 0) v.push_back(n);
		n++;
	}

	if (v.size() < K) cout << "0\n";
	else cout << v[K - 1] << "\n";

	return 0;
}