#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	char* c;
	scanf("%s", c);

	char* p = c;
	while (*p != '\0') {

		if (*p > 96 && *p < 123)
			printf("%c", *p - 32);
		else
			printf("%c", *p);
		p++;
	}

	return 0;
}