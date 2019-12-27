#include <iostream>
#include <vector>

using namespace std;

int main() {

	string str;
	cin >> str;
	int strSize = str.length();
	
	vector<int> v; // ( -4 [ -3 ] -2 ) -1
	bool flag = true;
	for (int i = 0; i < strSize; i++) {
		char a = str.at(i);
		if (a == '(') {
			v.push_back(-4);
		}
		else if (a == '[') {
			v.push_back(-3);
		}
		else if (a == ']') {
			int n = 0;
			if (v.empty()) {
				flag = false;
				break;
			}
			while (v.back() > 0) {
				n += v.back();
				v.pop_back();
			}
			if (n == 0)n = 1;
			if (v.back() == -3){
				v.pop_back();
				v.push_back(n * 3);
			}
			else {
				flag = false;
				break;
			}
		}
		else if (a == ')') {
			int n = 0;
			if (v.empty()) {
				flag = false;
				break;
			}
			while (v.back() > 0) {
				n += v.back();
				v.pop_back();
			}
			if (n == 0)n = 1;
			if (v.back() == -4) {
				v.pop_back();
				v.push_back(n * 2);
			}
			else {
				flag = false;
				break;
			}
		}

	}
	int siz = v.size(), sum = 0;
	for (int i = 0; i < siz; i++) {
		if (v[i] < 0) {
			flag = false;
			break;
		}
		sum += v[i];
	}
	if (flag) {
		cout << sum << "\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}