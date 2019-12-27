#include <iostream>

using namespace std;

int main() {

	string str;
	cin >> str;
	int strSize = str.length();
	int res = 0, cnt = 0;
	for (int i = 0; i < strSize; i++) {
		char a = str.at(i);
		if (a == '(') {
			if (str.at(i + 1) == ')') {
				res += cnt;
				i++;
			}
			else {
				cnt++;
			}
		}
		else {
			res += 1;
			cnt--;
		}
	}

	cout << res << "\n";

	return 0;
}