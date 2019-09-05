#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001]; // 찾을 숫자
int N;

int find(int n) {
	if (binary_search(arr, arr + N, n))
		return 1;
	else
		return 0;
}

int main() {
	int M;
	int b;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}
	sort(arr, arr + N);

	scanf("%d ", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d ", &b);
		printf("%d\n", find(b));
	}
	return 0;
}