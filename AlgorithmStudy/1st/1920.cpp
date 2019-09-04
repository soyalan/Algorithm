#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001]; // 찾을 숫자
int N;

int find(int n) {
	int mid;
	int first = 0;
	int last = N - 1;
	while (first <= last) {
		mid = (first + last) / 2;
		if (arr[mid] == n)return 1;
		else if (arr[mid] > n) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
		if (mid >= N || mid < 0)break;
	}

	return 0;
}

int main() {
	int M;
	int b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &b);
		printf("%d\n", find(b));
	}
	return 0;
}