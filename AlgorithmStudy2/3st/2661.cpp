#include <iostream>
#include <string>

using namespace std;

bool check = false;

bool good(int* arr, int cnt) {
	for (int i = 0; i <= cnt; i++) {
		for (int l = 0; l <= cnt / 2; l++) {
			if (i + l * 2 >= cnt) break;
			string str1 = "";
			string str2 = "";
			for (int j = 0; j <= l; j++) {
				str1 += (arr[i + j] + '0');
				str2 += (arr[i + j + l + 1] + '0');
			}
			if (str1 == str2) return false;
		}
	}
	return true;
}

void dfs(int* arr, int N, int cnt) {
	if (check) return;
	if (cnt == N) {
		for (int i = 0; i < N; i++) cout << arr[i];
		cout << "\n";
		check = true;
		return;
	}

	for (int i = 1; i < 4; i++) {
		arr[cnt] = i;
		if (good(arr, cnt)) dfs(arr, N, cnt + 1);
	}
}

int main() {

	int N;
	cin >> N;
	int* arr = new int[N];

	dfs(arr, N, 0);

	delete[] arr;
	return 0;
}