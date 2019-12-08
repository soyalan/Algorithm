#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	int arr[26] = { 0 };
	cin >> str;
	int siz = str.length();
	int max = 0;
	for (int i = 0; i < siz; i++) {
		int a = str.at(i) - 97;
		if (a < 0) a += 32;
		arr[a]++;
		if (max < arr[a])max = arr[a];
	}
	char a;
	bool check = false;
	bool doe = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) {
			if (check) {
				doe = true;
				break;
			}
			check = true;
			a = i + 65;
		}
	}
	if (doe) printf("?\n");
	else printf("%c\n", a);



	return 0;
}