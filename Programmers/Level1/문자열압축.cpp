#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int checksize(int cnt) {
	int res = 0;
	while (cnt != 0) {
		res++;
		cnt /= 10;
	}
	return res;
}

int solution(string s) {
	int answer = s.length();
	int i, siz = answer, len = siz / 2;
	for (int l = 1; l <= len; l++) {
		int count = 0;
		for (i = 0; i <= siz - l;) {
			bool check = false;
			int cnt = 0;
			while (!check) {
				int dep = i + l * ++cnt, t = 0;
				for (int z = 0; z < l; z++) {
					if (siz < dep + z) break;
					if (s[dep + z] != s[i + t++]) check = true;
				}
			}
			if (cnt > 1) count += checksize(cnt);
			count += l;
			i += cnt * l;
		}
		count += (siz - i);
		if (answer > count) answer = count;
	}
	return answer;
}

int main() {

	vector<string> s = {
		"aabbaccc",
		"ababcdcdababcdcd",
		"abcabcdede",
		"abcabcabcabcdededededede",
		"xababcdcdababcdcd"
	};
	
	for (int i = 0; i < s.size(); i++) {
		printf("%d\n", solution(s[i]));
	}

	return 0;
}