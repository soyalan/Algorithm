#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main() {
	for (int k = 0; k < 10; k++) {
		int length;
		string arr;
		cin >> length;
		cin >> arr;

		string post;
		char a;
		stack<char> op;
		for (int i = 0; i < length; i++) {
			a = arr.at(i);
			if (a > 47 && a < 58) {
				post += a;
			}
			else if (a == '*') {
					op.push(a);
			}
			else if (a == '+') {
				if(op.empty()){
					op.push(a);
				}
				else if (op.top() == '+') {
					while (!op.empty()) {
						post += op.top();
						op.pop();
					}
					op.push(a);
				}
				else if(op.top() == '*') {
					while (op.top() == '*') {
						post += op.top();
						op.pop();
						if (op.empty()) break;
					}
					op.push(a);
				}
			}
		}
		while (!op.empty()) {
			post += op.top();
			op.pop();
		}

		stack<int> s;
		for (int i = 0; i < length; i++) {
			a = post.at(i);
			if (a > 47 && a < 58) {
				s.push(a - '0');
			}
			else {
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				if (a == '+') {
					s.push(num1 + num2);
				}
				else if (a == '*') {
					s.push(num1 * num2);
				}
			}
		}

		printf("#%d %d\n", k + 1, s.top());
	}

	return 0;
}