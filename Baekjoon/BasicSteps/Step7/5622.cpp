#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int arr[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

	string str;
	cin >> str;
	int siz = str.length();
	int time = 0;
	for (int i = 0; i < siz; i++) {
		char a = str.at(i) - 65;
		time += arr[a];
	}
	printf("%d\n", time);

	return 0;
}