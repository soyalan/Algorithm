#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main() {
	for (int k = 0; k < 10; k++) {
		int length;
		string arr;
		cin >> length;
		cin >> arr;

		char a;
		int result = 0;
		for (int i = 0; i < length; i++) {
			a = arr.at(i);
			if (a > 47 && a < 58)
				result += a - '0';
		}

		printf("#%d %d\n", k + 1, result);
	}

	return 0;
}