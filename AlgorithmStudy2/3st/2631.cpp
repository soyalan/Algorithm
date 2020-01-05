#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int* childs = new int[N];
	int* arr = new int[N];
	for (int i = 0; i < N; i++) cin >> childs[i];
	for (int i = 0; i < N; i++) arr[i] = 0;
	arr[0] = 1;
	int res = 0;
	for (int i = 1; i < N; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (childs[i] > childs[j]) {
				if (max < arr[j]) max = arr[j];
			}
		}
		arr[i] = max + 1;
		if (res < arr[i]) res = arr[i];
	}

	cout << N - res << "\n";

	delete[] childs;
	delete[] arr;
	return 0;
}