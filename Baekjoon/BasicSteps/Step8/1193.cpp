#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	int i = 0, j = 0;
	bool check = true;
	for (int n = 1; n < N; n++) {
		if (check) {
			if (i == 0) {
				j++;
				check = false;
			}
			else {
				i--;
				j++;
			}
		}
		else {
			if (j == 0) {
				i++;
				check = true;
			}
			else {
				i++;
				j--;
			}
		}
	}
	printf("%d/%d\n", i + 1, j + 1);

	return 0;
}