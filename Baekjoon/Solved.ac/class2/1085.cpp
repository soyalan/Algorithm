#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	int t1 = min(w - x, x);
	int t2 = min(h - y, y);
	cout << min(t1, t2) << "\n";

	return 0;
}