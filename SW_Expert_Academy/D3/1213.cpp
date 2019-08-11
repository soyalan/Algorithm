#include <stdio.h>
#include <iostream>
#include <string.h>

int main() {

	for (int k = 0; k < 10; k++) {
		int n;
		scanf("%d", &n);
		
		char find[11];
		scanf("%s", find);
		char target[1001];
		scanf("%s", target);
		
		int flength = strlen(find);
		int tlength = strlen(target);
		int cnt = 0;
		
		char* t = target;
		int full = 0;
		int test = 1;
		
		while (*t != '\0') {
			if (test == 1) {
				t--;
				test = 2;
			}
			char* f = &find[flength - 1];
			int move = 0;
			if (*(t + flength) == *f) { // 맨 끝 문자가 같다면
				f--;
				bool exist = true;
				for (int i = flength - 1; i > 0; i--) {
					if (*(t + i) == *f) {
						f--;
					}
					else {
						exist = false;
						break;
					}
				}
				if (exist) {
					cnt++;
				}
				move = flength;
			}
			else {  // 맨 끝 문자가 다르면
				bool exist = false;
				char* p = find;
				while (*p != '\0') {
					if (*(t + flength) == *p) {
						exist = true;
						move++;
						break;
					}
					move++;
					p++;
				}
				if (exist)
					move = flength - move;
				else
					move = flength;
			}
			t += move;
			full += move;
			if (full > tlength)
				break;
		}

		printf("#%d %d\n", k + 1, cnt);
	}

	return 0;
}