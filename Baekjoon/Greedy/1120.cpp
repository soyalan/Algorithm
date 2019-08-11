#include <stdio.h>
#include <iostream>
#include <string.h>

int main() {

	char arr[51];
	char brr[51];
	scanf("%s %s", arr, brr);
	int a = strlen(arr);
	int b = strlen(brr);

	int min = 100;
	for (int i = 0; i + a <= b; i++) {
		int cnt = 0;
		for (int j = 0; j < a; j++) {
			if (arr[j] != brr[i + j])
				cnt++;
		}
		if (min > cnt)
			min = cnt;
	}
	printf("%d\n", min);

	return 0;
}