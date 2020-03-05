#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int> > map[1001];
int dij[1001];
int track[1001];

void dijstra() {
	for (int i = 2; i <= N; i++) dij[i] = 1000000000;
	for (int i = 1; i <= N; i++) track[i] = -1;
	queue<pair<int, int> > q;
	q.push({ 1, 0 });

	while (!q.empty()) {
		int to = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (dij[to] < cost) continue;

		for (int i = 0; i < map[to].size(); i++) {
			int next = map[to][i].first;
			int ncost = cost + map[to][i].second;
			if (dij[next] > ncost) {
				dij[next] = ncost;
				q.push({ next, ncost });
				track[next] = to;
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int n = 0; n < M; n++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map[b].push_back({ a,c }); 
	}

	dijstra();

	int cnt = 0;
	for (int i = 1; i <= N; i++) if (track[i] != -1) cnt++;

	cout << cnt << "\n";
	for (int i = 1; i <= N; i++) {
		if (track[i] != -1) {
			cout << track[i] << " " << i << "\n";
		}
	}

	return 0;
}