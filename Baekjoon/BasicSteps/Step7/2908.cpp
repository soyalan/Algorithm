#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int A, B;
	scanf("%d %d", &A, &B);
	A = (A / 100) + (((A % 100) / 10) * 10) + ((A % 10) * 100);
	B = (B / 100) + (((B % 100) / 10) * 10) + ((B % 10) * 100);
	
	if (A > B) printf("%d\n", A);
	else printf("%d\n", B);
	
	return 0;
}