#include <stdio.h>
#include <iostream>

using namespace std;

int arr[16][2];
int maxs;
int limit;

void dfs(int day, int sum) {
	if (day == limit) {
		if (maxs < sum) maxs = sum;
		return;
	}
	
	if (day + arr[day][0] <= limit)
		dfs(day + arr[day][0], sum + arr[day][1]);
	dfs(day + 1, sum);
}

int main() {
	cin >> limit;
	for (int i = 0; i < limit; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	
	dfs(0, 0);

	printf("%d\n", maxs);

	return 0;
}