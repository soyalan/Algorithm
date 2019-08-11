#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	for (int k = 0; k < n; k++) {
		int number;
		scanf("%d", &number);
		vector<pair<int, int> > v;
		for (int i = 0; i < number; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back(pair<int, int>(a, b));
		}
		sort(v.begin(), v.end());

		int cnt = 0;

		for (int i = 0; i < number; i++) {
			bool check = true;
			for (int j = 0; j < i; j++) {
				if (v[i].second > v[j].second) {
					check = false;
					break;
				}
			}
			if (check) 
				cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}