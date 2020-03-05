#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	map<string, int> m;
	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		m[str] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> str;
		m[str] += 1;
		if (m[str] == 2) cnt++;
	}

	cout << cnt << "\n";
	map<string, int>::iterator it = m.begin();
	for (; it != m.end(); it++) if ((*it).second == 2) cout << (*it).first << "\n";

	return 0;
}