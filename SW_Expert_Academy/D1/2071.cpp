#include <iostream>
#include <stdio.h>
#include <math.h>

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		double sum = 0;
		for (int j = 0; j < 10; j++) {
			int number;
			scanf("%d", &number);
			sum += number;
		}
		printf("#%d %.f\n", i + 1, round((sum / 10)));
	}

	return 0;
}