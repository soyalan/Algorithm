#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int pass;
	int num;
	scanf("%d %d", &pass, &num);

	printf("%d\n", pass - num + 1);

	return 0;
}