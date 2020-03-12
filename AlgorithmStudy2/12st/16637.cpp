#include <iostream>

using namespace std;

int N;
int arr[10];
char op[10];
int res = 0x80000000;

int cal(int a, int b, char c) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
}

void dfs(int i, int n) {
	if (i == N / 2) {
		if (n > res) res = n;
		return;
	}

	dfs(i + 1, cal(n, arr[i + 1], op[i]));
	if (i + 1 < N / 2) dfs(i + 2, cal(n, cal(arr[i + 1], arr[i + 2], op[i + 1]), op[i]));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		if (i % 2 == 0) arr[cnt] = a - '0';
		else {
			op[cnt] = a;
			cnt++;
		}
	}

	dfs(0, arr[0]);
	cout << res << "\n";

	return 0;
}