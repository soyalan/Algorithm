#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	sort(arr, arr + n);
	int max = 0;
	for (int i = 1; i <= n; i++) {
		int weight = arr[n-i] * i;
		if (max < weight)
			max = weight;
	}
	printf("%d\n", max);

	return 0;
}