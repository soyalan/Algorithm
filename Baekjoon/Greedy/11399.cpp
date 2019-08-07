#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	int arr[1001];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	int time = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		time += sum;
	}
	printf("%d\n", time);
	
	return 0;
}