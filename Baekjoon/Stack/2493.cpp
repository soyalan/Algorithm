#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, max = 0;
	cin >> N;
	vector<pair<int, int> > v;
	vector<pair<int, int> >::iterator it;
	int n;
	for (int i = 0; i < N; i++) {
		scanf(" %d", &n);
		if (v.empty()) {
			printf("0 ");
		}
		else {
			if (max < n) {
				it = v.begin();
			}
			else {
				it = v.end() - 1;
				while (it->second < n) {
					if (it == v.begin()) {
						break;
					}
					it--;
				}
			}
			if (it == v.begin() && it->second < n) printf("0 ");
			else printf("%d ", it->first);
		}
		v.push_back({ i + 1,n });
		if (max < n) max = n;
	}

	printf("\n");
	return 0;
}