#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	for (int k = 0; k < 10; k++) {

		int n;
		scanf("%d", &n);
		int arr[101] = { 0 };
		for (int i = 0; i < 100; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + 100);
		for (int i = 0; i < n; i++) {
			int maxindex = 99;
			int minindex = 0;
			while (1) {
				if (arr[maxindex] > arr[maxindex - 1])
					break;
				else {
					maxindex--;
				}
			}
			while (1) {
				if (arr[minindex] < arr[minindex + 1])
					break;
				else {
					minindex++;
				}
			}
			arr[maxindex]--;
			arr[minindex]++;
		}
		printf("#%d %d\n", k + 1, arr[99] - arr[0]);
	}


	return 0;
}