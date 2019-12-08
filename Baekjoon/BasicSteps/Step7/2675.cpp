#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n;
		scanf(" %d", &n);
		string str;
		cin >> str;
		int siz = str.length();
		for (int i = 0; i < siz; i++) {
			char a = str.at(i);
			for (int j = 0; j < n; j++) {
				printf("%c", a);
			}
		}
		printf("\n");
	}

	return 0;
}