#include <iostream>
#include <list>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, k;
	cin >> N >> k;

	list<int> l;
	for (int i = 0; i < N; i++) l.push_back(i + 1);

	list<int>::iterator it = l.begin();
	cout << "<";
	while (1) {
		for (int i = 0; i < k - 1; i++) {
			if (it == l.end()) it = l.begin();
			it++;
		}
		if (it == l.end()) it = l.begin();
		cout << *it;
		it = l.erase(it);

		if (l.empty()) break;
		cout << ", ";
	}
	cout << ">\n";

	return 0;
}