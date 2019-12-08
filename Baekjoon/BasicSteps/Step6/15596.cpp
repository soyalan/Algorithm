#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

long long sum(std::vector<int>& a) {
	long long ans = 0;
	int siz = a.size();
	for (int i = 0; i < siz; i++) ans += a[i];
	return ans;
}

int main() {

	vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };

	long long res = sum(arr);

	printf("%lld\n", res);

	return 0;
}