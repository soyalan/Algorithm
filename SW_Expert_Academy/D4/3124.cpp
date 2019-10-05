#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
};

bool compare(Edge a, Edge b) {
	return a.distance < b.distance;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int L, a, b, d;
		cin >> N >> L;
		vector<Edge> v;
		for (int i = 0; i < L; i++) {
			cin >> a >> b >> d;
			v.push_back(Edge(a - 1, b - 1, d));
		}
		sort(v.begin(), v.end(), compare);

		int parent[100001];
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		int sum = 0, siz = v.size();

		for (int i = 0; i < siz; i++) {
			if (!findParent(parent, v[i].node[0], v[i].node[1])) {
				sum += v[i].distance;
				unionParent(parent, v[i].node[0], v[i].node[1]);
			}
		}
		printf("#%d %d\n", t + 1, sum);
	}

	return 0;
}