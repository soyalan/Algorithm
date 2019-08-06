#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	int n = 1;
	for (int i = 0; i <= num; i++) {
		printf("%d ", n);
		n *= 2;
	}

	return 0;
}