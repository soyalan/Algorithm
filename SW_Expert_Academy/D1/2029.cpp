#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("#%d %d %d\n", i + 1, a / b, a % b);
	}
	return 0;
}