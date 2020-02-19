#include <iostream>
#include <map>

using namespace std;

int cnt[100000];
int arr[100000];

void init() {
	for (int i = 0; i < 100000; i++) {
		cnt[i] = 1;
		arr[i] = i;
	}
}

int getP(int n) {
	if (arr[n] == n) return n;
	else {
		int tmp = getP(arr[n]);
		cnt[tmp] += cnt[n];
		cnt[n] = 0;
		arr[n] = tmp;
		return arr[n];
	}
}

void uni(int a, int b) {
	a = getP(a);
	b = getP(b);
	if (a > b) {
		arr[a] = b;
		cnt[b] += cnt[a];
		cnt[a] = 0;
	}
	else {
		arr[b] = a;
		cnt[a] += cnt[b];
		cnt[b] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		map<string, int> m;
		int num = 0;

		init();
		for (int i = 0; i < N; i++) {
			string f1, f2;
			cin >> f1 >> f2;
			int a, b;
			if (m.find(f1) == m.end()) {
				m.insert({ f1,num });
				a = num;
				num++;
			}
			else a = m[f1];
			if (m.find(f2) == m.end()) {
				m.insert({ f2,num });
				b = num;
				num++;
			}
			else b = m[f2];

			if (getP(a) != getP(b)) {
				uni(a, b);
			}
			cout << cnt[getP(a)] << "\n";
		}
	}


	return 0;
}