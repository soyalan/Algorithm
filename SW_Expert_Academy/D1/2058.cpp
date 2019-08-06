#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int num;
	int sum = 0;
	scanf("%d", &num);
	while (num != 0) {
		int a = num % 10;
		sum += a;
		num /= 10;
	}
	printf("%d\n", sum);
	return 0;
}