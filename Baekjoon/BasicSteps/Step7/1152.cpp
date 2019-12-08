#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int cnt = 0;
	char a = 'a';
	bool check = false;
	while ((a = getchar()) != '\n') {
		if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
			if (!check) cnt++;
			check = true;
		}
		else {
			check = false;
		}
	}
	printf("%d\n", cnt);

	return 0;
}