#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int main() {
	for (int k = 0; k < 10; k++) {
		int n;
		cin >> n;
		list<int> ls;
		int number;
		for (int i = 0; i < n; i++) {
			cin >> number;
			ls.push_back(number);
		}
		cin >> n;
		char op;
		int x;
		int y;
		list<int>::iterator it;
		for (int i = 0; i < n; i++) {
			cin >> op;
			if (op == 'I') {
				cin >> x;
				cin >> y;
				it = ls.begin();
				advance(it, x);
				list<int> nls;
				for (int j = 0; j < y; j++) {
					cin >> number;
					nls.push_back(number);
				}
				ls.insert(it, nls.begin(), nls.end());
			}
			else if (op == 'D') {
				cin >> x;
				cin >> y;
				it = ls.begin();
				advance(it, x);
				for (int j = 0; j < y; j++) {
					it = ls.erase(it);
				}
			}
		}
		it = ls.begin();
		cout << "#" << k + 1 << " ";
		for (int i = 0; i < 10; i++) {
			cout << *it++ << " ";
		}
		cout << endl;

	}
	return 0;
}