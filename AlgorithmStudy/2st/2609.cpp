#include <stdio.h>
#include <iostream>

using namespace std;


int main() {
	int A, B;
	cin >> A >> B;
	int a = A, b = B;

	while (b > 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	printf("%d\n%d\n", a, A * B / a);

	return 0;
}