#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	cin >> str;
	int siz = str.length();
	int c[26] = { 0 };
	for (int i = 0; i < 26; i++) {
		c[i] = -1;
	}
	for (int i = 0; i < siz; i++) {
		char a = str.at(i) - 97;
		if (c[a] >= 0) continue;
		c[a] = i;
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");

	return 0;
}