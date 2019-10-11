/*
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cnt;

class net {
public:
	int num;
	int parent;
	string name;
	net(string name) {
		this->name = name;
		this->num = cnt;
		this->parent = cnt;
		cnt++;
	}
};

int getNet(vector<net>& v, string n) {
	int siz = v.size();
	for (int i = 0; i < siz; i++) {
		if (n == v[i].name) return i;
	}
	return -1;
}

int getParent(vector<net>&n, net n1) {
	if (n1.parent == n1.num) return n1.parent;
	return n1.parent = getParent(n, n[n1.parent]);
}

void unionNet(vector<net>& n, net& n1, net& n2) {
	int temp1 = getParent(n, n1);
	int temp2 = getParent(n, n2);
	if (temp1 > temp2) n1.parent = n2.parent;
	else n2.parent = n1.parent;
}

int numNet(vector<net>& v, int n) {
	int siz = v.size();
	int res = 0;
	for (int i = 0; i < siz; i++) {
		int temp = getParent(v, v[i]);
		if (n == temp) res++;
	}
	return res;
}

void print(vector<net>& v) {
	printf("==========\n");
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].num << " " << v[i].parent << " " << v[i].name << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cnt = 0;
		int n;
		cin >> n;
		vector<net> v;
		for (int i = 0; i < n; i++) {
			string str1 = "";
			string str2 = "";
			cin >> str1 >> str2;
			int temp1 = getNet(v, str1);
			int temp2 = getNet(v, str2);
			if (temp1 == -1) {
				v.push_back(net(str1));
				temp1 = cnt - 1;
			}
			if (temp2 == -1) {
				v.push_back(net(str2));
				temp2 = cnt - 1;
			}

			print(v);

			unionNet(v, v[temp1], v[temp2]);
			
			print(v);

			printf("net = %d\n", numNet(v, v[temp2].parent));
		}
		
	}

	return 0;
}
*/