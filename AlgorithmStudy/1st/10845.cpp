#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main() {
	int N, num;
	cin >> N;
	queue<int> q;
	char c[6];
	for (int i = 0; i < N; i++) {
		scanf("%s", c);
		if (!strcmp(c, "push")) {
			scanf("%d", &num);
			q.push(num);
		}
		else if (!strcmp(c, "pop")) {
			if (q.empty()) printf("-1\n");
			else {
				num = q.front();
				q.pop();
				printf("%d\n", num);
			}
		}
		else if (!strcmp(c, "size")) {
			printf("%d\n", q.size());
		}
		else if (!strcmp(c, "empty")) {
			if (q.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(c, "front")) {
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.front());
		}
		else if (!strcmp(c, "back")) {
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.back());
		}

	}
	return 0;
}