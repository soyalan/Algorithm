#include <stdio.h>

int main() {

	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int temp = A * B * C;
	int arr[10] = { 0 };
	while(temp){
		arr[temp % 10]++;
		temp /= 10;
	}
	for (int i = 0; i < 10; i++) printf("%d\n", arr[i]);

	return 0;
}