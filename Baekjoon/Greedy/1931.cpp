#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	
	int n;
	scanf("%d", &n);

	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back(pair<int, int>(x, y));
	}
	sort(v.begin(), v.end(), compare);

	vector<pair<int, int> >::iterator it;
	int endtime = 0, cnt = 0;
	for (it = v.begin(); it != v.end(); it++) {
		if ((*it).first < endtime)
			continue;
		endtime = (*it).second;
		cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}
