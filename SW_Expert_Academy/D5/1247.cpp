/*
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
		cin >> N;
		pair<int, int> home;
		pair<int, int> cop;
		vector<pair<int, int> > cus;
		vector<Edge> v;
		cin >> cop.first >> cop.second >> home.first >> home.second;
		int a, b;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			cus.push_back({ a, b });
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				v.push_back(Edge(i, j, (abs(cus[i].first - cus[j].first) + abs(cus[i].second - cus[j].second))));
			}
		}
		sort(v.begin(), v.end(), compare);

		int parent[11];
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		int sum = 0, siz = v.size();

		for (int i = 0; i < siz; i++) {
			printf("%d -> (%d %d) %d\n", i, v[i].node[0], v[i].node[1], v[i].distance);
		}

		for (int i = 0; i < siz; i++) {
			if (!findParent(parent, v[i].node[0], v[i].node[1])) {
				sum += v[i].distance;
				unionParent(parent, v[i].node[0], v[i].node[1]);
			}
		}
		int dis, hmin = 10000000, cmin = 10000000;
		for (int i = 0; i < N; i++) {
			dis = (abs(home.first - cus[i].first) + abs(home.second - cus[i].second));
			if (dis < hmin) hmin = dis;
			dis = (abs(cop.first - cus[i].first) + abs(cop.second - cus[i].second));
			if (dis < cmin) cmin = dis;
		}
		printf("%d\n", sum + hmin + cmin);
	}

	return 0;
}
*/