#include <stdio.h>
#include <iostream>

using namespace std;

char upside[3][3];
char downside[3][3];
char frontside[3][3];
char backside[3][3];
char leftside[3][3];
char rightside[3][3];

void UpRight() {
	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = upside[0][i];
	for (int i = 0; i < 2; i++) upside[0][i] = upside[2 - i][0];
	for (int i = 0; i < 2; i++) upside[2 - i][0] = upside[2][2 - i];
	upside[2][1] = upside[1][2];
	for (int i = 0; i < 3; i++) upside[2 - i][2] = temp[2 - i];
	
	for (int i = 0; i < 3; i++) temp[i] = frontside[0][i];
	for (int i = 0; i < 3; i++) frontside[0][i] = rightside[0][i];
	for (int i = 0; i < 3; i++) rightside[0][i] = backside[0][i];
	for (int i = 0; i < 3; i++) backside[0][i] = leftside[0][i];
	for (int i = 0; i < 3; i++) leftside[0][i] = temp[i];
}

void DownRight() {
	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = downside[0][i];
	for (int i = 0; i < 2; i++) downside[0][i] = downside[2 - i][0];
	for (int i = 0; i < 2; i++) downside[2 - i][0] = downside[2][2 - i];
	downside[2][1] = downside[1][2];
	for (int i = 0; i < 3; i++) downside[2 - i][2] = temp[2 - i];

	for (int i = 0; i < 3; i++) temp[i] = frontside[2][i];
	for (int i = 0; i < 3; i++) frontside[2][i] = leftside[2][i];
	for (int i = 0; i < 3; i++) leftside[2][i] = backside[2][i];
	for (int i = 0; i < 3; i++) backside[2][i] = rightside[2][i];
	for (int i = 0; i < 3; i++) rightside[2][i] = temp[i];
}

void FrontRight() {
	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = frontside[0][i];
	for (int i = 0; i < 2; i++) frontside[0][i] = frontside[2 - i][0];
	for (int i = 0; i < 2; i++) frontside[2 - i][0] = frontside[2][2 - i];
	frontside[2][1] = frontside[1][2];
	for (int i = 0; i < 3; i++) frontside[2 - i][2] = temp[2 - i];

	for (int i = 0; i < 3; i++) temp[i] = upside[2][i];
	for (int i = 0; i < 3; i++) upside[2][i] = leftside[2-i][2];
	for (int i = 0; i < 3; i++) leftside[2-i][2] = downside[0][2-i];
	for (int i = 0; i < 3; i++) downside[0][2-i] = rightside[i][0];
	for (int i = 0; i < 3; i++) rightside[i][0] = temp[i];
}

void BackRight() {
	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = backside[0][i];
	for (int i = 0; i < 2; i++) backside[0][i] = backside[2 - i][0];
	for (int i = 0; i < 2; i++) backside[2 - i][0] = backside[2][2 - i];
	backside[2][1] = backside[1][2];
	for (int i = 0; i < 3; i++) backside[2 - i][2] = temp[2 - i];

	for (int i = 0; i < 3; i++) temp[i] = upside[0][i];
	for (int i = 0; i < 3; i++) upside[0][i] = rightside[i][2];
	for (int i = 0; i < 3; i++) rightside[i][2] = downside[2][i];
	for (int i = 0; i < 3; i++) downside[2][i] = leftside[i][0];
	for (int i = 0; i < 3; i++) leftside[i][0] = temp[i];
}

void LeftRight() {
	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = leftside[0][i];
	for (int i = 0; i < 2; i++) leftside[0][i] = leftside[2 - i][0];
	for (int i = 0; i < 2; i++) leftside[2 - i][0] = leftside[2][2 - i];
	leftside[2][1] = leftside[1][2];
	for (int i = 0; i < 3; i++) leftside[2 - i][2] = temp[2 - i];

	for (int i = 0; i < 3; i++) temp[i] = upside[i][0];
	for (int i = 0; i < 3; i++) upside[i][0] = backside[2 - i][2];
	for (int i = 0; i < 3; i++) backside[2-i][2] = downside[i][0];
	for (int i = 0; i < 3; i++) downside[i][0] = frontside[i][0];
	for (int i = 0; i < 3; i++) frontside[i][0] = temp[i];
}

void RightRight() {
	char temp[3];
	for (int i = 0; i < 3; i++) temp[i] = rightside[0][i];
	for (int i = 0; i < 2; i++) rightside[0][i] = rightside[2 - i][0];
	for (int i = 0; i < 2; i++) rightside[2 - i][0] = rightside[2][2 - i];
	rightside[2][1] = rightside[1][2];
	for (int i = 0; i < 3; i++) rightside[2 - i][2] = temp[2 - i];

	for (int i = 0; i < 3; i++) temp[i] = upside[2-i][2];
	for (int i = 0; i < 3; i++) upside[2-i][2] = frontside[2-i][2];
	for (int i = 0; i < 3; i++) frontside[2-i][2] = downside[2-i][2];
	for (int i = 0; i < 3; i++) downside[2-i][2] = backside[i][0];
	for (int i = 0; i < 3; i++) backside[i][0] = temp[i];
}

int main() {
	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				upside[i][j] = ((i * 3) + j + 1) + '0';
				downside[i][j] = 'y';
				frontside[i][j] = 'r';
				backside[i][j] = 'o';
				leftside[i][j] = 'g';
				rightside[i][j] = 'b';
			}
		}
		int c;
		cin >> c;
		for (int k = 0; k < c; k++) {
			char a, b;
			int cnt = 1;
			scanf(" %c%c", &a, &b);
			if (b == '-') cnt = 3;
			if (a == 'U') {
				for (int i = 0; i < cnt; i++) UpRight();
			}
			else if (a == 'D') {
				for (int i = 0; i < cnt; i++) DownRight();
			}
			else if (a == 'F') {
				for (int i = 0; i < cnt; i++) FrontRight();
			}
			else if (a == 'B') {
				for (int i = 0; i < cnt; i++) BackRight();
			}
			else if (a == 'L') {
				for (int i = 0; i < cnt; i++) LeftRight();
			}
			else {
				for (int i = 0; i < cnt; i++) RightRight();
			}
		}	
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", upside[i][j]);
			}
			printf("\n");
		}

	}

	return 0;
}