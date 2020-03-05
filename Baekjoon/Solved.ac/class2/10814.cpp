#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool op(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
	if (a.first.second == b.first.second) return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<pair<pair<int, int>, string> > v(N);

	for (int i = 0; i < N; i++) {
		v[i].first.first = i;
		cin >> v[i].first.second >> v[i].second;
	}

	sort(v.begin(), v.end(), op);

	for (int i = 0; i < N; i++) {
		cout << v[i].first.second << " " << v[i].second << "\n";
	}

	return 0;
}