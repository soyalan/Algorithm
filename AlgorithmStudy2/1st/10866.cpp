#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	deque<int> que;
	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		if (str == "push_front") {
			int n;
			cin >> n;
			que.push_front(n);
		}
		else if (str == "push_back") {
			int n;
			cin >> n;
			que.push_back(n);
		}
		else if (str == "pop_front") {
			if (que.empty()) cout << "-1\n";
			else {
				cout << que.front() << "\n";
				que.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (que.empty()) cout << "-1\n";
			else {
				cout << que.back() << "\n";
				que.pop_back();
			}
		}
		else if (str == "size") {
			cout << que.size() << "\n";
		}
		else if (str == "empty") {
			if (que.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "front") {
			if (que.empty()) cout << "-1\n";
			else cout << que.front() << "\n";
		}
		else if (str == "back") {
			if (que.empty()) cout << "-1\n";
			else cout << que.back() << "\n";
		}
	}

	return 0;
}