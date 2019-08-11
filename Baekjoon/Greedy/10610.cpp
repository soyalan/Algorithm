#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {

	char p[100001];
	scanf("%s", p);
	int arr[100001];
	int cnt = strlen(p);
	bool zero = false;
	
	for (int i = 0; i < cnt; i++) {
		arr[i] = (int)((p[i]) - '0');
		if (arr[i] == 0)
			zero = true;
	}

	if (zero) {
		int sum = 0;
		for (int i = 0; i < cnt; i++) {
			sum += arr[i];
		}
		if (sum == 0)
			printf("-1\n");
		else if (sum % 3 == 0) {
			sort(p, p + cnt);
			for (int i = 0; i < cnt; i++) {
				printf("%d", p[cnt - i - 1] - '0');
			}
			printf("\n");
		}
		else
			printf("-1\n");
	}
	else
		printf("-1\n");

	return 0;
}