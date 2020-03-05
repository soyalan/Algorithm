#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	int card[100];
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> card[i];

	int res = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = card[i] + card[j] + card[k];
				if (sum > M) continue;
				if (M - res > M - sum) res = sum;
			}
		}
	}

	cout << res << "\n";

	return 0;
}