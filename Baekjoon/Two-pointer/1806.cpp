#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	int* start = arr, * end = arr;
	int min = 0x7FFFFFFF, res = 0, sum = arr[0];
	while (end < arr + N && start <= end) {
		if (sum < M) {
			end++;
			sum += *end;
		}
		else {
			res = end - start + 1;
			if (min > res) min = res;
			
			sum -= *start;
			start++;
			
		}
	}

	if(min == 0x7FFFFFFF) cout << "0\n";
	else cout << min << "\n";

	free(arr);
	return 0;
}