#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int temp = C - B;
	if (temp > 0) {
		int cnt = A / temp;
		printf("%d\n", cnt + 1);
	}
	else {
		printf("-1\n");
	}

	return 0;
}