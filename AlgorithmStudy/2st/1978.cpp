#include <stdio.h>
#include <iostream>

using namespace std;

bool find(int x) {
	if (x == 1) return false;

	for (int i = 2; i < x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	int number, cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> number;
		if (find(number))cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}