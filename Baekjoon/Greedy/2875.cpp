#include <stdio.h>
#include <iostream>

int main() {

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int cnt = 0;
	int total = n + m;
	
	while ((total - k) >= 3) {
		if (n < 2)break;
		if (m < 1)break;
		n -= 2;
		m -= 1;
		cnt++;
		total -= 3;
	}
	printf("%d\n", cnt);

	return 0;
}