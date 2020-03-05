#include <iostream>
#include <algorithm>

using namespace std;

bool check(int arr[3]) {
	sort(arr, arr + 3);
	if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	while (arr[0] && arr[1] && arr[2]) {
		if (check(arr)) cout << "right\n";
		else cout << "wrong\n";
		cin >> arr[0] >> arr[1] >> arr[2];
	}
	
	return 0;
}