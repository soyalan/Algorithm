#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int TC;
	scanf(" %d\n", &TC);
	int cnt = 0;
	for (int t = 0; t < TC; t++) {
		vector<char> v;
		vector<char>::iterator it;
		char a = '0';
		while ((a = getchar()) != '\n') {
			if (v.empty()) {
				v.push_back(a);
				continue;
			}
			it = v.end() - 1;
			if (*it == a) {
				v.pop_back();
			}
			else {
				v.push_back(a);
			}
		}
		if (v.empty()) {
			cnt++;
		}

	}
	printf("%d\n", cnt);

	return 0;
}