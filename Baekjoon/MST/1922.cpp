#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class line {
public:
	int a, b;
	int dis;
	
	line(int a, int b, int dis) {
		this->a = a;
		this->b = b;
		this->dis = dis;
	}

	bool operator < (line& l) {
		return this->dis < l.dis;
	}
};

int getParent(int* arr, int n) {
	if (n == arr[n]) return n;
	return arr[n] = getParent(arr, arr[n]);
}

void makeUnion(int* arr, int a, int b) {
	a = getParent(arr, a);
	b = getParent(arr, b);
	if (a > b) arr[a] = b;
	else arr[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<line> v;
	for (int i = 0; i < M; i++) {
		int a, b, dis;
		cin >> a >> b >> dis;
		v.push_back(line(a, b, dis));
	}

	sort(v.begin(), v.end());

	int* arr = new int[N + 1];
	for (int i = 0; i <= N; i++) arr[i] = i;

	int siz = v.size(), cnt = 0, res = 0;
	for (int i = 0; i < siz; i++) {
		int a = v[i].a;
		int b = v[i].b;
		if (getParent(arr, a) != getParent(arr, b)) {
			makeUnion(arr, a, b);
			res += v[i].dis;
			cnt++;
		}
		if (cnt == N)break;
	}

	cout << res << "\n";

	delete[] arr;
	return 0;
}