#include <stdio.h>

int main() {

	int N;
	scanf("%d", &N);
	int cnt = 0, n = N;
	while (1) {
		cnt++;
		n = ((n%10) * 10) + (((n / 10) + (n % 10)) % 10);
		if (N == n)break;
	}
	printf("%d\n", cnt);

	return 0;
}