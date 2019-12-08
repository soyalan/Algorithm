#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	cin >> str;
	int siz = str.length();
	int cnt = 0, i;
	for (i = 0; i < siz - 1; i++) {
		char a = str.at(i);
		if (a == 'c') {
			if (str.at(i + 1) == '=') {
				cnt++;
				i++;
				continue;
			}
			else if (str.at(i + 1) == '-') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (a == 'd') {
			if (str.at(i + 1) == '-') {
				cnt++;
				i++;
				continue;
			}
			else if (str.at(i + 1) == 'z') {
				if (i + 2 < siz) {
					if (str.at(i + 2) == '=') {
						cnt++;
						i+=2;
						continue;
					}
				}
			}
		}
		else if (a == 'l') {
			if (str.at(i + 1) == 'j') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (a == 'n') {
			if (str.at(i + 1) == 'j') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (a == 's') {
			if (str.at(i + 1) == '=') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (a == 'z') {
			if (str.at(i + 1) == '=') {
				cnt++;
				i++;
				continue;
			}
		}
		cnt++;

	}
	if (i == siz - 1) {
		cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}