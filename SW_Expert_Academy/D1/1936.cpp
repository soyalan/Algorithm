#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	if (a == 1) {
		if (b == 2) printf("B\n");
		else printf("A\n");
	}
	else if (a == 2) {
		if (b == 3) printf("B\n");
		else printf("A\n");
	}
	else {
		if (b == 1) printf("B\n");
		else printf("A\n");
	}

	return 0;
}