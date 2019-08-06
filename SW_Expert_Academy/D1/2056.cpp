#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int ymd;
		scanf("%d", &ymd);
		int date = ymd % 100;
		int month = (ymd % 10000) / 100;
		int year = ymd / 10000;
		bool error = false;

		if (month < 1 || month > 12 || date == 0)
			error = true;
		else {
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				if (date > 31) error = true;
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {
				if (date > 30) error = true;
			}
			else {
				if (date > 28) error = true;
			}
		}
		if (error)
			printf("#%d -1\n", i + 1);
		else
			printf("#%d %04d/%02d/%02d\n", i + 1, year, month, date);
	}
	return 0;
}