#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
vector<char> ch;

int cnt = 1;

bool insert(int n) {

	if (num.empty()) {
		num.push_back(cnt);
		cnt++;
		ch.push_back('+');
	}
	while (cnt <= n) {
		num.push_back(cnt);
		cnt++;
		ch.push_back('+');
	}
	if (cnt > n + 1) return true;
	return false;
}

bool remove(int n) {
	int temp = num.back();
	num.pop_back();
	ch.push_back('-');

	while (temp != n) {
		temp = num.back();
		num.pop_back();
		ch.push_back('-');
		if (num.empty()) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	int cnt = 1;
	bool flag = false;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		insert(n);
		if (flag) break;
		flag = remove(n);
	}
	if (flag) cout << "NO\n";
	else {
		int siz = ch.size();
		for (int i = 0; i < siz; i++) cout << ch[i] << "\n";
	}

	return 0;
}