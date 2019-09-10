#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>

using namespace std;

int main() {
	int N, num;
	cin >> N;
	deque<int> d;
	char c[11];
	for (int i = 0; i < N; i++) {
		scanf("%s", c);
		if (!strcmp(c, "push_front")) {
			scanf("%d", &num);
			d.push_front(num);
		}
		else if (!strcmp(c, "push_back")) {
			scanf("%d", &num);
			d.push_back(num);
		}
		else if (!strcmp(c, "pop_front")) {
			if (d.empty()) printf("-1\n");
			else {
				num = d.front();
				d.pop_front();
				printf("%d\n", num);
			}
		}
		else if (!strcmp(c, "pop_back")) {
			if (d.empty()) printf("-1\n");
			else {
				num = d.back();
				d.pop_back();
				printf("%d\n", num);
			}
		}
		else if (!strcmp(c, "size")) {
			printf("%d\n", d.size());
		}
		else if (!strcmp(c, "empty")) {
			if (d.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(c, "front")) {
			if (d.empty()) printf("-1\n");
			else printf("%d\n", d.front());
		}
		else if (!strcmp(c, "back")) {
			if (d.empty()) printf("-1\n");
			else printf("%d\n", d.back());
		}

	}
	return 0;
}