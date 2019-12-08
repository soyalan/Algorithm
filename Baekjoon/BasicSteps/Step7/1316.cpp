#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int T, cnt = 0;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		int siz = str.length();
		bool arr[26] = { false };
		bool check = true;
		arr[str.at(0) - 97] = true;
		for (int i = 1; i < siz; i++) {
			char a = str.at(i);
			if (a != str.at(i - 1)) {
				if (arr[a - 97]) {
					check = false;
					break;
				}
				arr[a - 97] = true;
			}
		}
		if (check) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}