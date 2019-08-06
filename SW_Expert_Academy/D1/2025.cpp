#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	int sum = 0;

	for (int i = 1; i <= num; i++)
		sum += i;
	printf("%d\n", sum);

	return 0;
}