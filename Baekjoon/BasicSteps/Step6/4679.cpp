#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int arr[10001] = { 0 };
	for (int i = 1; i < 10001; i++) {
		int temp = i;
		int temp2 = i;
		while (temp2) {
			temp += (temp2 % 10);
			temp2 /= 10;
		}
		if (temp > 10000) continue;
		arr[temp] = 1;
	}
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 0) printf("%d\n", i);
	}

	return 0;
}



