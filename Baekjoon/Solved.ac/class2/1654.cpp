#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, n;
	cin >> K >> N;
	vector<int> arr;
	for (int i = 0; i < K; i++) {
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	long long left = 1, right = arr[K-1], max = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++) cnt += (arr[i] / mid);

		if (cnt < N) right = mid - 1;
		else {
			left = mid + 1;
			max = (max, mid);
		}
	}

	cout << max << "\n";

	return 0;
}