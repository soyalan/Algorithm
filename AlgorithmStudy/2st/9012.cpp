#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	getchar();
	for (int i = 0; i < N; i++) {
		char a;
		int cnt = 0;
		bool check = true;
		while ((a = getchar()) != '\n') {
			if (a == '(')cnt++;
			else cnt--;
			if (cnt < 0) {
				check = false;
			}
		}
		if (cnt != 0) check = false;

		if (check)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}