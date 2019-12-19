#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int counting[26] = { 0 };
	string str;
	cin >> str;

	int strSize = str.length();
	for (int i = 0; i < strSize; i++) {
		counting[(str.at(i) - 97)]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << counting[i] << " ";
	}
	cout << "\n";

	return 0;
}