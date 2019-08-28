#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int number;
	cin >> number;
	for (int k = 0; k < number; k++) {
		int i, m, n, money, cnt = 0, temp;
		int arr[6] = { 0 };
		cin >> m >> n;
		money = m;
		while (money > 0) {
			arr[cnt++] = money % 10;
			money /= 10;
		}
		for (i = 0; i < cnt / 2; i++) {
			temp = arr[cnt - 1 - i];
			arr[cnt - 1 - i] = arr[i];
			arr[i] = temp;
		}
		// 
		for (i = 0; i < n; i++) {
			if (i < cnt) {
			int max = 0, maxi = i, min = arr[i], mini = 0;
				for (int j = i; j < cnt; j++) {
					if (max <= arr[j]) {
						max = arr[j];
						maxi = j;
					}
					if (min > arr[j]) {
						min = arr[j];
						mini = j;
					}
				}
				printf("max : %d. %d, min : %d. %d\n", maxi, max, mini, min);
				if (arr[i] <= max) {
					min = arr[i];
					mini = i;
				}
				if (maxi == mini) {
					n += 1;
					continue;
				}
				printf("max : %d. %d, min : %d. %d\n", maxi, max, mini, min);
				temp = arr[maxi];
				arr[maxi] = arr[mini];
				arr[mini] = temp;
				
			}
			else {
				temp = arr[cnt - 1];
				arr[cnt - 1] = arr[cnt - 2];
				arr[cnt - 2] = temp;
			}
			printf("-- ");
			for (int i = 0; i < cnt; i++) {
				printf("%d", arr[i]);
			}
			printf(" --\n");
		}

		printf("#%d ", k + 1);
		for (int i = 0; i < cnt; i++) {
			printf("%d", arr[i]);
		}
		printf("\n");

	}

	return 0;
}