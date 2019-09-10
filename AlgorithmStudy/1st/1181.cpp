#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool compare(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	int i = 0;
	while (a[i] == b[i]) {
		i++;
	}
	return a[i] < b[i];
}

int main() {
	int N;
	cin >> N;
	vector<string> v;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}
	unique(v.begin(), v.end());
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
		if (i != v.size() - 1) {
			while (v[i + 1] == v[i])i++;
		}
	}

	return 0;
}