#include <iostream>
#include <stdlib.h>

using namespace std;

int queueSize = 100;

int* append(int* que, int cnt, int head) {
	int* temp = (int*)malloc(sizeof(int) * queueSize * 2);
	for (int i = 0; i < cnt; i++) {
		temp[i] = que[head++];
	}
	queueSize *= 2;
	free(que);
	return temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int* que = (int*)malloc(sizeof(int) * queueSize);
	int head = 0;
	int tail = 0;
	int cnt = 0;

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			if (tail == queueSize) {
				que = append(que, cnt, head);
				head = 0;
				tail = cnt;
			}
			que[tail] = n;
			cnt++;
			tail++;
		}
		else if (str == "pop") {
			if (cnt) {
				cout << que[head] << "\n";
				head++;
				cnt--;
			}
			else cout << "-1\n";
		}
		else if (str == "size") {
			cout << cnt << "\n";
		}
		else if (str == "empty") {
			if (cnt) cout << "0\n";
			else cout << "1\n";
		}
		else if (str == "front") {
			if (cnt) cout << que[head] << "\n";
			else cout << "-1\n";
		}
		else if (str == "back") {
			if (cnt) cout << que[tail - 1] << "\n";
			else cout << "-1\n";
		}
	}

	free(que);

	return 0;
}