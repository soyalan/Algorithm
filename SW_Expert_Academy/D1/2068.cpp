#include <iostream>
#include <stdio.h>
#include <math.h>

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int max = 0;
		for (int j = 0; j < 10; j++) {
			int number;
			scanf("%d", &number);
			if (max < number) max = number;
		}
		printf("#%d %d\n", i + 1, max);
	}

	return 0;
}