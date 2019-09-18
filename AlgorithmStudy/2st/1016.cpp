/*
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

	long long a, b, i, j, temp;
	cin >> a >> b;
	int cnt = 0;
	for (i = a; i <= b; i++) {
		bool check = false;
		for (j = 2; j <= i; j++) {
			temp = sqrt(j);
			if (temp * temp != j) continue;
			if (i % j == 0) {
				check = true;
				break;
			}
		}
		if (!check)cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
*/