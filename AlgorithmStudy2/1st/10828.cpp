#include <iostream>
#include <stdlib.h>

using namespace std;

int stackSize = 100;

int* append(int* stack) {
	int* temp = (int*)malloc(sizeof(int) * stackSize * 2);
	for (int i = 0; i < stackSize; i++) {
		temp[i] = stack[i];
	}
	stackSize *= 2;
	free(stack);
	return temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, cnt = -1;
	cin >> N;
	int* stack = (int*)malloc(sizeof(int) * stackSize);
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			if (cnt < stackSize - 1) {
				cnt++;
				stack[cnt] = n;
			}
			else {
				stack = append(stack);
				cnt++;
				stack[cnt] = n;
			}
		}
		else if (str == "pop") {
			if (cnt >= 0) {
				cout << stack[cnt] << "\n";
				cnt--;
			}
			else {
				cout << cnt << "\n";
			}
		}
		else if (str == "size") {
			cout << cnt + 1 << "\n";
		}
		else if (str == "empty") {
			if (cnt >= 0) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if(str == "top"){
			if (cnt >= 0) {
				cout << stack[cnt] << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
	
	free(stack);

	return 0;
}