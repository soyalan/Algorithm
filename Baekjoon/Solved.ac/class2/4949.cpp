#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(string str) {
	vector<char> v;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			v.push_back(str[i]);
		}
		else if (str[i] == ')') {
			if (v.empty()) return false;
			if (v[v.size() - 1] != '(') return false;
			v.pop_back();
		}
		else if (str[i] == ']') {
			if (v.empty()) return false;
			if (v[v.size() - 1] != '[') return false;
			v.pop_back();
		}
	}
	if (v.size() > 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	getline(cin, str, '.');

	while (str.size() > 1) {
		if (check(str)) cout << "yes\n";
		else cout << "no\n";

		getline(cin, str, '.');
	}

	return 0;
}