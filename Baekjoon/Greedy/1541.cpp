#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

	char arr[51];
	scanf("%s", arr);
	char* p = arr;
	queue<string> q;
	int state = 1;
	while (*p != '\0') {
		if (*p == '-') {
			if (state) {
				q.push("-");
				q.push("(");
				p++;
				state = 0;
			}
			else {
				q.push(")");
				q.push("-");
				q.push("(");
				p++;
			}
		}
		else if (*p == '+') {
			q.push("+");
			p++;
		}
		else {
			char n[7];
			int k = 0;
			while ((*p != '+') && (*p != '-') && (*p != '\0')) {
				n[k++] = *p;
				p++;
			}
			n[k] = '\0';
			q.push((string)n);
		}
	}
	if (!state)
		q.push(")");
	
	int result = 0;
	while (!q.empty()) {
		string str = q.front();
		q.pop();
		int num1;
		if (str != "-" && str != "+") {
			num1 = atoi(str.c_str());
			result += num1;
		}
		else if (str == "-") {
			string str1 = q.front();
			q.pop();
			int sum = 0;
			while (str1 != ")") {
				str1 = q.front();
				q.pop();
				if (str1 != "+")
					sum += atoi(str1.c_str());
			}
			result -= sum;
		}
		else if (str == "+") {
			string str2 = q.front();
			q.pop();
			result += atoi(str2.c_str());
		}
	}
	cout << result << endl;

	return 0;
}