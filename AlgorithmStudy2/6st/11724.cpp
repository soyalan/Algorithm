#include <iostream>
#include <set>

using namespace std;

int getParent(int* arr, int n) {
	if (arr[n] == n) return n;
	else return arr[n] = getParent(arr, arr[n]);
}

void uni(int* arr, int a, int b) {
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

	int* arr = new int[N + 1];
	for (int i = 0; i <= N; i++) arr[i] = i;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (getParent(arr, a) != getParent(arr, b)) uni(arr, a, b);
	}
	
	set<int> s;
	for (int i = 1; i <= N; i++) s.insert(getParent(arr, arr[i]));

	cout << s.size() << "\n";

	delete[] arr;
	return 0;
}