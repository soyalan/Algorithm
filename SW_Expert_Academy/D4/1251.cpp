/*
#include <Stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(pair<long long, pair<int, int>> a, pair<long long, pair<int, int>> b) {
	return a.first < b.first;
}
int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int N;
		long long result = 0;
		double E;
		int XY[1001][2];
		int uni[1001];
		cin >> N;
		for (int i = 0; i < N; i++) cin >> XY[i][0];
		for (int i = 0; i < N; i++) cin >> XY[i][1];
		cin >> E;
		for (int i = 0; i < N; i++) uni[i] = i;

		// 출력 시작
		printf("--------\nN : %d, E : %f\n", N, E);
		for (int i = 0; i < N; i++) {
			printf("%d : (%d, %d)\n", i, XY[i][0], XY[i][1]);
		}
		printf("--------\n");
		// 출력 종료

		vector<pair<long long, pair<int, int>>> v;
		long long distance;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				distance = round(sqrt(pow((XY[i][0] - XY[j][0]), 2) + pow((XY[i][1] - XY[j][1]), 2)));
				v.push_back(pair<long long, pair<int, int>>(distance, pair<int, int>(i, j)));
			}
		}
		sort(v.begin(), v.end(), compare);

		// uni
		for (int i = 0; i < N; i++) printf("%d ", i);
		printf("\n");
		for (int i = 0; i < N; i++) printf("%d ", uni[i]);
		printf("\n\n");
		int cnt = 0;
		vector<pair<long long, pair<int, int>>>::iterator it = v.begin();
		int a, b, c;
		long long d;
		for (; it != v.end(); it++) {
			a = it->second.first;
			b = it->second.second;
			d = it->first;
			if (uni[b] == uni[a]) { // 이미 연결됨
				printf("pass--(%d, %d) : %lld\n", a, b, d);
				continue;
			}
			else if (uni[b] == b) { // 연결이 없는 상태
				if (a == uni[a]) {
					uni[b] = a;
					cnt++;
					result =  result + round((pow(d, 2) * E));
					printf("--(%d, %d) : %lld\n", a, b, d);
				}
				else {
					c = uni[a];
					uni[a] = c;
					while (c != uni[c]) {
						c = uni[c];
						uni[c] = c;
					}
					uni[b] = a;
					cnt++;
					result = result + round((pow(d, 2) * E));
					printf("--(%d, %d) : %lld\n", a, b, d);
				}
			}
			else {
				if (uni[a] > uni[b]) {
					c = uni[b];
					uni[a] = c;
					while (c != uni[c]) {
						c = uni[c];
						uni[c] = c;
					}
					uni[a] = c;
				}
				else {
					c = uni[b];
					uni[b] = uni[a];
					while (c != uni[c]) {
						c = uni[c];
						uni[c] = uni[a];
					}
					uni[c] = uni[a];
				}
				cnt++;
				result = result + round((pow(d, 2) * E));
				printf("!!--(%d, %d) : %lld\n", a, b, d);
			}
		// uni
		for (int i = 0; i < N; i++) printf("%d ", i);
		printf("\n");
		for (int i = 0; i < N; i++) printf("%d ", uni[i]);
		printf("\n\n");
		if (cnt == N - 1)break;
		}


		// 출력 시작
		it = v.begin();
		for(;it != v.end();it++){
			printf("(%d, %d) : %lld\n", it->second.first, it->second.second, it->first);
		}
		// 출력 종료



		printf("#%d %lld\n", k + 1, result);
	}

	return 0;
}

*/