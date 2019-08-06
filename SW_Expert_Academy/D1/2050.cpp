#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	char* c;
	scanf("%s", c);

	char* p = c;
	while (*p != '\0') {
		printf("%d ", *p - 64);
		p++;
	}

	return 0;
}