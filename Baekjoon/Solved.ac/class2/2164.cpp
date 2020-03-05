#include <iostream>
#include <list>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	list<int> l;
	for (int i = 0; i < N; i++) {
		l.push_back(i + 1);
	}

	int cnt = N;
	while (cnt > 1) {
		l.pop_front();
		l.push_back(l.front());
		l.pop_front();
		cnt--;
	}

	cout << l.front() << "\n";


	return 0;
}