#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main() {
	int N, num;
	cin >> N;
	vector<int> v;
	char c[6];
	for (int i = 0; i < N; i++) {
		scanf("%s", c);
		if (!strcmp(c, "push")) {
			scanf("%d", &num);
			v.push_back(num);
		}
		else if (!strcmp(c, "pop")) {
			if (v.empty()) printf("-1\n");
			else {
				num = v.back();
				v.pop_back();
				printf("%d\n", num);
			}
		}
		else if (!strcmp(c, "size")) {
			printf("%d\n", v.size());
		}
		else if (!strcmp(c, "empty")) {
			if (v.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(c, "top")) {
			if (v.empty()) printf("-1\n");
			else printf("%d\n", v.back());
		}

	}
	return 0;
}