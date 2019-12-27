#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	int* start = arr, * end = arr;
	int cnt = 0, sum = arr[0];
	while (end < arr + N) {
		if (sum < M) {
			end++;
			sum += *end;
		}
		else {
			if (sum == M)cnt++;
			if (start < end) {
				sum -= *start;
				start++;
			}
			else if (start == end) {
				end++;
				sum += *end;
			}
		}
	}
	while (sum >= M) {
		if (start > end) break;
		sum -= *start;
		start++;
		if (sum == M)cnt++;
	}

	cout << cnt << "\n";
		
	return 0;
}