#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int arr[1001];
int time[1001];
int waste[1001];
vector<int> v[1001];

void ans() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int n = q.front();
		int t = time[n] + waste[n];
		q.pop();

		for (int i = 0; i < v[n].size(); i++) {
			int m = v[n][i];
			arr[m]--;
			if (waste[m] < t) waste[m] = t;
			if (arr[m] == 0) q.push(m);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int K, W;
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> time[i];
			waste[i] = 0;
			v[i].clear();
			arr[i] = 0;
		}
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			arr[b]++;
		}
		cin >> W;

		ans();

		cout << waste[W] + time[W] << "\n";
	}

	return 0;
}