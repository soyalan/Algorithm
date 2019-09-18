#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	if (a == 0) return false;
	if (b == 0) return true;
	return a < b;
}

int N;
int arr[4000002];

void f() {
	for (int i = 2; i <= sqrt(N); i++) {
		if (!arr[i]) continue;
		for (int j = i * 2; j <= N; j += i) {
			arr[j] = 0;
		}
	}
}

int main() {

	cin >> N;
	
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}

	f();

	arr[N + 1] = 0;
	sort(arr, arr + N + 1, compare);

	int sum, cnt = 0;
	for (int i = 0; i <= N; i++) {
		if (arr[i] == 0) break;
		sum = 0;
		for (int j = i; j <= N; j++) {
			if (arr[j] == 0) break;
			sum += arr[j];
			if (sum == N)cnt++;
			if (sum > N)break;
		}
	}

	printf("%d\n", cnt);


	return 0;
}