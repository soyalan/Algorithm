#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int* arr = new int[N + 1] { 0 };
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (arr[i] > arr[i - j * j]) {
				arr[i] = arr[i - j * j] + 1;
			}
		}
	}

	cout << arr[N] << "\n";

	delete[] arr;

	return 0;
}