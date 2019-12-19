#include <iostream>

using namespace std;

int main() {

	int N;
	int room[10] = { 0 };
	
	cin >> N;
	if (N == 0) room[0]++;
	while (N > 0) {
		int n = N % 10;
		N /= 10;
		room[n]++;
	}
	room[6] = (room[6] + room[9] + 1) / 2;

	int res = 0;
	for (int i = 0; i < 9; i++) {
		if (res < room[i]) res = room[i];
	}
	cout << res << "\n";
	return 0;
}