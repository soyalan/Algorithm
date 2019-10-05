#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int getParents(int parent[], int x) {
	if(parent[x] == x) {
		return x;
	}
	return parent[x] = getParents(parent, parent[x]);
}

void unionParents(int parent[], int a, int b) {
	a = getParents(parent, a);
	b = getParents(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParents(int parent[], int a, int b) {
	a = getParents(parent, a);
	b = getParents(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N;
	int parent[201];
	int pass[1001];
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	cin >> M;
	int n;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> n;
			if (n == 1) {
				unionParents(parent, i, j);
			}
		}
	}
	bool check = true;
	cin >> pass[1];
	for (int i = 2; i <= M; i++) {
		cin >> pass[i];
		if (!findParents(parent, pass[i - 1], pass[i])) {
			check = false;
			break;
		}
	}



	if (check) printf("YES\n");
	else printf("NO\n");

	return 0;
}