#include <stdio.h>

int main() {

	int A;
	scanf("%d", &A);

	if (!(A % 4)) {
		if (!(A % 400)) printf("1\n");
		else if (!(A % 100)) printf("0\n");
		else printf("1\n");
	}
	else printf("0\n");

	return 0;
}