#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	int* res = (int*)malloc(sizeof(int) * N);
	res[0] = 1;

	int max = 1;
	for (int i = 1; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if(temp < res[j]) temp = res[j];
			}
		}
		res[i] = temp + 1;
		if (max < res[i]) max = res[i];
	}

	cout << max << "\n";

	free(arr);
	free(res);

	return 0;
}