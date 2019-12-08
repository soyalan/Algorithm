#include <stdio.h>

int main() {

	int temp;
	bool as = true;
	bool de = true;
	scanf("%d", &temp);
	for (int i = 1; i < 8; i++) {
		int n;
		scanf(" %d", &n);
		if (temp > n) {
			as = false;
		}
		if (temp < n) {
			de = false;
		}
		temp = n;
	}
	if (as) printf("ascending\n");
	else if (de) printf("descending\n");
	else printf("mixed\n");
	
	return 0;
}