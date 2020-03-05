#include <iostream>

#define M 1234567891
#define r 31
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L;
	char a;
	cin >> L;

	long long n, res = 0, tmp = 1;
	for (int i = 0; i < L; i++) {
		cin >> a;
		n = (long long)a - 96;
		res = (res + (n * tmp)) % M;
		tmp = (tmp * r) % M;
	}
	
	cout << res << "\n";

	return 0;
}