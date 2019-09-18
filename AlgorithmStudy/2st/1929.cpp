#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


int main() {

	int a, b;
	cin >> a >> b;
	int *arr = new int[b + 1];
	for (int i = 2; i <= b; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(b); i++) {
		if (!arr[i]) continue;
		for (int j = i*2; j <= b; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = a; i <= b; i++) {
		if (arr[i]) printf("%d\n", arr[i]);
	}

	return 0;
}