#include <iostream>
#include <vector>

using namespace std;

int main() {

	int A, B, C;
	cin >> A >> B >> C;

	long long temp = A % C, cnt = 1, res = 0;
	vector<long long> v;

	while (cnt <= B) {
		v.push_back(temp);
		temp = temp * temp % C;
		cnt *= 2;
	}

	int siz = v.size();
	temp = 0;
	for (int i = siz - 1; i >= 0; i--) {
		cnt = 1;
		for (int j = 0; j < i; j++) cnt = cnt << 1;
		if (res + cnt <= B) {
			if (temp == 0) temp = 1;
			res += cnt;
			temp = temp * v[i] % C;
		}
	}

	cout << temp << "\n";

	return 0;
}