#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;
		int a = w * p;
		int b;
		if (r > w) {
			b = q;
		}
		else {
			b = q + (w - r) * s;
		}
		int result;
		a > b ? result = b : result = a;
		printf("#%d %d\n", k + 1, result);
	}


	return 0;
}