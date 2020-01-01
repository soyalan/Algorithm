#include <iostream>
#include <algorithm>

using namespace std;

long long tree(int* arr, int N, int cnt) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		long long temp = arr[i] - cnt;
		if(temp > 0) sum += (arr[i] - cnt);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long M;
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	sort(arr, arr + N);

	long long temp = 0;
	int left = 0, right = arr[N - 1], mid, res = 0;
	while (left <= right) {
		mid = (left + right) / 2;

		temp = tree(arr, N, mid);

		if (temp < M) right = mid - 1;
		else {
			if (res < mid) res = mid;
			left = mid + 1;
		}
	}

	cout << res << "\n";

	delete[] arr;

	return 0;
}