#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);

	int sum = 0;
	int cnt[8001] = { 0 };
	int mcnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i];
		cnt[v[i] + 4000]++;
		if (mcnt < cnt[v[i] + 4000]) mcnt = cnt[v[i] + 4000];
	}

	sort(v.begin(), v.end());

	int arr[4];
	arr[0] = round((double)sum / N);
	arr[1] = v[N / 2];
	bool check = false;
	for (int i = 0; i < N; i++) {
		if (cnt[v[i] + 4000] == mcnt) {
			if (!check) {
				check = true;
				arr[2] = v[i];
				cnt[v[i] + 4000] = 0;
			}
			else {
				arr[2] = v[i];
				break;
			}
		}
	}
	arr[3] = v[N - 1] - v[0];
	
	for (int i = 0; i < 4; i++) cout << arr[i] << "\n";

	return 0;
}