/*
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		char p[400002];
		int n;
		cin >> p;
		cin >> n;
		getchar();
		char a = 'A';
		vector<int> v;
		while ((a = getchar()) != '\n') {
			int sum = 0, num = a - '0';
			if (num > 0 && num <= 9) {
				sum += num;
				a = getchar();
				num = a - '0';
				if (num >= 0 && num <= 9) {
					sum = (sum * 10) + num;
					a = getchar();
					num = a - '0';
					if (num == 0) {
						sum *= 10;
					}
				}
			}
			if (!sum)continue;
			v.push_back(sum);
		}

		vector<int>::iterator it;

		int id = 0;
		bool check = true;
		while (p[id] != '\0') {
			char a = p[id];
			if (a == 'R') {
				reverse(v.begin(), v.end());
			}
			else {
				if (v.empty()) {
					check = false;
					break;
				}
				it = v.begin();
				it = v.erase(it);
			}
			id++;
		}

		if (check) {
			printf("[");
			for (it = v.begin(); it != v.end() - 1; it++) {
				printf("%d,", *it);
			}
			printf("%d]\n", *it);
		}
		else {
			printf("error\n");
		}

	}

	return 0;
}
*/