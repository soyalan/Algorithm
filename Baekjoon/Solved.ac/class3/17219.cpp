#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	map<string, string> m;
	for (int i = 0; i < N; i++) {
		string s, p;
		cin >> s >> p;
		m[s] = p;
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		cout << m[s] << "\n";
	}

	return 0;
}