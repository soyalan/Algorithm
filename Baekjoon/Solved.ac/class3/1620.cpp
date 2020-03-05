#include <iostream>
#include <map>
#include <vector>

using namespace std;

int st(string str) {
	int n = 0;
	for (int i = 0; i < str.size(); i++) {
		char a = str[i];
		n = (10 * n) + (a - '0');
	}
	return n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	map<string, int> m;
	vector<string> v(N + 1);
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		v[i] = str;
		m.insert({ str, i });
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') {
			int n = st(str);
			cout << v[n] << "\n";
		}
		else {
			cout << m[str] << "\n";
		}
	}

	return 0;
}