#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int* arr, int n) {
	if (arr[n] == n) return n;
	else return arr[n] = getParent(arr, arr[n]);
}

void uni(int* arr, int a, int b) {
	a = getParent(arr, a);
	b = getParent(arr, b);
	if (a > b) arr[a] = b;
	else arr[b] = a;
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first.first < b.first.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, E;
	cin >> V >> E;
	int* arr = new int[V + 1];
	for (int i = 0; i <= V; i++) arr[i] = i;

	vector<pair<pair<int, int>, int> > v;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v.push_back({ {a, b}, c });
	}

	sort(v.begin(), v.end(), compare);

	int res = 0;
	for (int i = 0; i < E; i++) {
		a = v[i].first.first;
		b = v[i].first.second;
		if (getParent(arr, a) != getParent(arr, b)) {
			uni(arr, a, b);
			res += v[i].second;
		}
	}

	cout << res << "\n";
	delete[] arr;
	return 0;
}