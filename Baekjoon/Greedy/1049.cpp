#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define NUM 6

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	vector <pair<int, int> > v;
	for (int k = 0; k < m; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(pair<int, int>(a, b));
	}
	sort(v.begin(), v.end());
	int min;
	// case 1
	int cnt = 0;
	int c = n;
	while (c > 0) {
		c -= 6;
		cnt += v[0].first;
	}
	min = cnt;

	// case 2
	cnt = 0;
	c = n;
	while (c > 6) {
		c -= 6;
		cnt += v[0].first;
	}
	sort(v.begin(), v.end(), compare);
	while (c > 0) {
		c -= 1;
		cnt += v[0].second;
	}
	if (min > cnt)
		min = cnt;

	// case 3
	cnt = 0;
	while (n > 0) {
		n -= 1;
		cnt += v[0].second;
	}
	if (min > cnt)
		min = cnt;

	printf("%d\n", min);
	return 0;
}