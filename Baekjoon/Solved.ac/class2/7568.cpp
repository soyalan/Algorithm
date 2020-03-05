#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	pair<int, int> arr[50];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	

	for (int i = 0; i < N; i++) {
		int score = 1;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) score++;
		}
		cout << score << " ";
	}
	cout << "\n";

	return 0;
}