#include <iostream>

using namespace std;

bool check(string str) {
	int left = 0, right = str.size() - 1;
	while (left < right) {
		if (str[left] != str[right]) return false;
		left++;
		right--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	while (str != "0") {
		if (check(str)) cout << "yes\n";
		else cout << "no\n";
		cin >> str;
	}

	return 0;
}