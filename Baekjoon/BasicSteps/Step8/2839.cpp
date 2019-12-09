#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	int arr[5001] = { 0 };
	arr[3] = 1;
	arr[5] = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i]) {
			if ((arr[i + 3] > arr[i] + 1) || arr[i + 3] == 0) arr[i + 3] = arr[i] + 1;
			if ((arr[i + 5] > arr[i] + 1) || arr[i + 5] == 0) arr[i + 5] = arr[i] + 1;
		}
	}
	if (arr[N]) {
		printf("%d\n", arr[N]);
	}
	else {
		printf("-1\n");
	}

	return 0;
}