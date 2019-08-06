#include <iostream>
#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		char c;
		if (a < b) c = '<';
		else if (a > b) c = '>';
		else c = '=';

		printf("#%d %c\n", i + 1, c);
	}

	return 0;
}