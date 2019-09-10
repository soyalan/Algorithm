#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int N, n1, n2;
	cin >> N;
	vector<pair<int, int> > v;
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2;
		v.push_back(pair<int, int>(n1, n2));
	}
	sort(v.begin(), v.end(), compare);
	vector<pair<int, int> >::iterator it = v.begin();

	for (; it != v.end(); it++) {
		printf("%d %d\n", it->first, it->second);
	}

	return 0;
}