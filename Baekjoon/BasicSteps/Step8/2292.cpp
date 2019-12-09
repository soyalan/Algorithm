#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	long long N;
	scanf("%lld", &N);
	int cnt = 1;
	long long temp = 1;
	while (temp < N) {
		temp += (cnt * 6);
		cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}