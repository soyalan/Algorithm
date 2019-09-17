#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v;
	int result[5001];

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	int index = 0, max = N;
	for (int i = 0; i < N; i++) {
		index = index + K;
		while (index > max) {
			index -= max;
		}
		result[i] = v[index - 1];
		v.erase(v.begin() + index - 1);
		max--;
		index--;
	}

	printf("<");
	for (int i = 0; i < N - 1; i++) {
		printf("%d, ", result[i]);
	}
	printf("%d>\n", result[N - 1]);


	return 0;
}