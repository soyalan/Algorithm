#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		string str1, str2;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			cin >> str1 >> str2;
			if (m.find(str2) == m.end()) m[str2] = 1;
			else m[str2] += 1;
		}

		int tmp = 1;
		map<string, int>::iterator it = m.begin();
		for (; it != m.end(); it++) tmp *= ((*it).second + 1);

		cout << tmp - 1 << "\n";
	}

	return 0;
}