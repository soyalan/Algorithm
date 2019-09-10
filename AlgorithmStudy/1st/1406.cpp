#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int main() {
	char str[100001];
	scanf("%s", str);
	list<char> l;
	char *p = str;
	while (*p != '\0') {
		l.push_back(*p);
		p++;
	}
	list<char>::iterator it = l.end();

	int N;
	char a;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == 'P') {
			cin >> a;
			it = l.insert(it, a);
			it++;
		}
		else if (a == 'L') {
			if (it == l.begin()) continue;
				it--;
		}
		else if (a == 'D') {
			if (it == l.end()) continue;
				it++;
		}
		else if (a == 'B') {
			if (it == l.begin()) continue;
			it--;
			it = l.erase(it);
		}
	}


	for (it = l.begin(); it != l.end(); it++) {
		printf("%c", *it);
	}
	printf("\n");

	return 0;
}