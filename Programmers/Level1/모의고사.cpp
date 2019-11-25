#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int number[3][10] = {
	{1,2,3,4,5},
	{2,1,2,3,2,4,2,5},
	{3,3,1,1,2,2,4,4,5,5}
	};
	int ans[3] = { 0 };
	int siz = answers.size(), temp1 = 0, temp2 = 0, temp3 = 0;
	
	for (int i = 0; i < siz; i++) {
		if (answers[i] == number[0][temp1++]) ans[0]++;
		if (answers[i] == number[1][temp2++]) ans[1]++;
		if (answers[i] == number[2][temp3++]) ans[2]++;
		if (temp1 == 5) temp1 = 0;
		if (temp2 == 8) temp2 = 0;
		if (temp3 == 10) temp3 = 0;
	}

	int max = 0;
	for (int i = 0; i < 3; i++)	if (max < ans[i]) max = ans[i];
	for (int i = 0; i < 3; i++) if (ans[i] == max) answer.push_back(i + 1);

	return answer;
}

int main() {

	vector<int> answers = { 1,3,2,4,2 };

	vector<int> answer = solution(answers);

	for (auto a : answer) {
		cout << a << '\n';
	}

	return 0;
}