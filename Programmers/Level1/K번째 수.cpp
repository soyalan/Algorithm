#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sorting(int& arr, int& brr) {
	
}

vector<int> solution(vector<int> narray, vector<vector<int>> commands) {
	vector<int> answer;
	int siz = commands.size();
	int arr[100];
	for (int n = 0; n < siz; n++) {
		int i = commands[n][0] - 1;
		int j = commands[n][1] - 1;
		int k = commands[n][2] - 1;
		int m;
		for (m = 0; m <= j - i; m++) arr[m] = narray[i + m];
		sort(arr, arr + m);
		answer.push_back(arr[k]);
	}

	return answer;
}

int main() {
	vector<int> narray = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int> > commands = {
		vector<int>({2, 5, 3}),
		vector<int>({4, 4, 1}),
		vector<int>({1, 7, 3})
	};

	vector<int> answer = solution(narray, commands);

	for (int a : answer) {
		cout << a << endl;
	}
	
	return 0;
}