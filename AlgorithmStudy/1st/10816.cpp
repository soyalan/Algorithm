#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M, a;
	scanf("%d ", &N);
	vector<int> v;
	for (int i = 0; i < N; i++) {
		scanf("%d ", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	scanf("%d ", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d ", &a);
		printf("%d ", upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a));
	}
	printf("\n");


	return 0;
}