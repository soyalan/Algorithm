#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int arr[10001] = { 0 };
	int N, a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		arr[a]++;
	}

	for (int i = 1; i < 10001; i++) {
		while(arr[i]--){
			printf("%d\n", i);
		}
	}

	return 0;
}