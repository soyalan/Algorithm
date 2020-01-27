#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int arr[10001] = { 0 };
	priority_queue<int> big;
	int one = 0;
	int zero = 0;
	priority_queue<int, vector<int>, greater<int> > small;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] < 0) small.push(arr[i]);
		else if (arr[i] == 0) zero++;
		else if (arr[i] == 1) one++;
		else big.push(arr[i]);
	}

	int res = 0;

	while (!big.empty()) {
		int temp = big.top();
		big.pop();
		if (!big.empty()) {
			temp = temp * big.top();
			big.pop();
		}
		res += temp;
	}

	res += one;

	while (!small.empty()) {
		int temp = small.top();
		small.pop();
		if (!small.empty()) {
			temp = temp * small.top();
			small.pop();
			res += temp;
		}
		else if (!zero) res += temp;
	}

	cout << res << "\n";

	return 0;
}