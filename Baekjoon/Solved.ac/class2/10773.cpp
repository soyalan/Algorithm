#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, n;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n) v.push_back(n);
		else v.pop_back();
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) sum += v[i];

	cout << sum << "\n";

	return 0;
}