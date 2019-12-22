#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		int strSize = str.length();
		char* stack = (char*)malloc(sizeof(char) * strSize);
		int cnt = -1;
		bool flag = true;
		for (int i = 0; i < strSize; i++) {
			char a = str.at(i);
			if (a == '(') {
				cnt++;
				stack[cnt] = a;
			}
			else {
				if (cnt == -1) {
					flag = false;
					break;
				}
				cnt--;
			}
		}
		if (cnt != -1) flag = false;
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		free(stack);
	}

	return 0;
}