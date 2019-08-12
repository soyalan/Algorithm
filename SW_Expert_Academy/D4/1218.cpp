#include <stdio.h>
#include <iostream>

int main() {

	for (int k = 0; k < 10; k++) {
		int t;
		scanf("%d ", &t);
		int arr[4] = { 0 }; // 0 = (), 1 = [], 2 = {}. 3 = <>
		for (int i = 0; i < t; i++) {
			char c = getchar();
			switch (c) {
			case '(':
				arr[0]++;
				break;
			case ')':
				arr[0]--;
				break;
			case '[':
				arr[1]++;
				break;
			case ']':
				arr[1]--;
				break;
			case '{':
				arr[2]++;
				break;
			case '}':
				arr[2]--;
				break;
			case '<':
				arr[3]++;
				break;
			case '>':
				arr[3]--;
				break;
			}
		}
		bool zero = true;
		for (int i = 0; i < 4; i++) {
			if (arr[i])
				zero = false;
		}
		if (zero)
			printf("#%d 1\n", k + 1);
		else
			printf("#%d 0\n", k + 1);
		
	}

	return 0;
}