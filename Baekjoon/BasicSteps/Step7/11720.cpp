#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	getchar();
	int sum = 0;
	for (int i = 0; i < N; i++) {
		char a;
		scanf("%c", &a);
		sum += a - '0';
	}
	printf("%d\n", sum);

	return 0;
}