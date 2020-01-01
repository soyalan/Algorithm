#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int* res = (int*)malloc(sizeof(int) * (k + 1));
	for (int i = 0; i <= k; i++) res[i] = 0;

	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= k; i++) {
			if (i == arr[j]) res[i]++;
			else if (i > arr[j])	res[i] += res[i - arr[j]];
		}
	}

	cout << res[k] << "\n";

	free(arr);
	free(res);

	return 0;
}