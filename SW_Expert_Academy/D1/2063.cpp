#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	int arr[200] = { 0 };

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + num);
	printf("%d\n", arr[num / 2]);
	return 0;
}