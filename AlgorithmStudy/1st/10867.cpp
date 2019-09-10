#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, num;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	vector<int>::iterator it;
	vector<int>::iterator it2;
	it2 = unique(v.begin(), v.end());
	for (it = v.begin(); it != it2; it++) {
		printf("%d ", *it);
	}
	printf("\n");

	return 0;
}