#include <iostream>
#include <queue>

using namespace std;

int left(int n) {
	int temp = 0;
	if (n != 0) temp = n / 1000;
	int res = (n % 1000) * 10;
	return res + temp;
}

int right(int n) {
	int temp = n % 10;
	int res = 0;
	if (n != 0) res = n / 10;
	return res + temp * 1000;
}

void bfs(int num1, int num2) {
	queue<pair<int, string> > q;
	bool visited[10000] = { false };
	visited[num1] = true;
	q.push({ num1,"" });

	while (!q.empty()) {
		int n = q.front().first;
		string str = q.front().second;
		q.pop();
		if (n == num2) {
			cout << str << "\n";
			return;
		}

		int tmp = (n * 2) % 10000;
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push({ tmp, str + "D" });
		}

		tmp = n - 1;
		if (tmp == -1) tmp = 9999;
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push({ tmp, str + "S" });
		}

		tmp = left(n);
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push({ tmp, str + "L" });
		}

		tmp = right(n);
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push({ tmp, str + "R" });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		bfs(num1, num2);
	}


	return 0;
}