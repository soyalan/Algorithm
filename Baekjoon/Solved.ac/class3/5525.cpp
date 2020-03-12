#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, S;
	cin >> N >> S;
	string str;
	cin >> str;

	int res = 0;
	for (int i = 0; i < str.size(); i++) {
		int cnt = 0;
		if (str[i] == 'I') {
			while (i < str.size() && str[i + 1] == 'O' && str[i + 2] == 'I') {
				i += 2;
				cnt++;
				if (cnt >= N) res++;
			}
		}
	}

	cout << res << "\n";

	return 0;
}