/*
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class shark {
public:
	int number, row, col, speed, direction, size;
	bool life;
	shark(int number, int row, int col, int speed, int direction, int size) {
		this->number = number;
		this->row = row;
		this->col = col;
		this->speed = speed;
		this->direction = direction;
		this->size = size;
		this->life = true;
	}
};

int R, C, M;
int arr[101][101];
vector<shark> v;
int cnt;

void catchShark(int n) {
	for (int i = 1; i <= R; i++) {
		if (arr[i][n]) {
			v[arr[i][n] - 1].life = false;
			cnt = cnt + v[arr[i][n] - 1].size;
			arr[i][n] = 0;
			return;
		}
	}
}

void moveShark() {
	vector<pair<int, int> > ch;
	for (int i = 0; i < M; i++) {
		shark &s = v[i];
		if (!s.life)continue;
		arr[s.row][s.col] = 0;
		if (s.direction == 1 || s.direction == 2) {
			if (s.direction == 1)
				s.row = s.row - s.speed;
			else
				s.row = s.row + s.speed;

			while (!(s.row >= 1 && s.row <= R)) {
				if (s.row == 1) {
					s.direction = 2;
				}
				else if (s.row < 1) {
					s.row = -s.row;
					s.row += 2;
					s.direction = 2;
				}
				if (s.row >= R) {
					s.row = R + (R - s.row);
					s.direction = 1;
				}
			}
		
		}
		else {
			if (s.direction == 4)
				s.col = s.col - s.speed;
			else
				s.col = s.col + s.speed;

			while (!(s.col >= 1 && s.col <= C)) {
				if (s.col == 1) {
					s.direction = 3;
				}
				else if (s.col < 1) {
					s.col = -s.col;
					s.col += 2;
					s.direction = 3;
				}
				if (s.col >= C) {
					s.col = C + (C - s.col);
					s.direction = 4;
				}
			}
		}

		if (!arr[s.row][s.col]) {
			arr[s.row][s.col] = s.number;
		}
		else if (s.number != v[arr[s.row][s.col] - 1].number) {
			ch.push_back(pair<int, int>(s.number, v[arr[s.row][s.col] - 1].number));
		}
		
	}
	if (ch.size()) {
		vector<pair<int, int> >::iterator it = ch.begin();

		for (; it != ch.end(); it++) {
			shark& s1 = v[it->first - 1];
			shark& s2 = v[it->second - 1];
			if ((s1.row == s2.row) && (s1.col == s2.col)) {
				if (s1.size > s2.size) {
					s2.life = false;
					arr[s1.row][s1.col] = s1.number;
				}
				else {
					s1.life = false;
					arr[s2.row][s2.col] = s2.number;
				}
			}
			else {
				if (arr[s1.row][s1.col] == 0) {
					arr[s1.row][s1.col] = s1.number;
				}
				else if (s1.number != v[arr[s1.row][s1.col] - 1].number) {
					ch.push_back(pair<int, int>(s1.number, v[(arr[s1.row][s1.col]) - 1].number));
				}
				if (arr[s2.row][s2.col] == 0) {
					arr[s2.row][s2.col] = s2.number;
				}
				else if(s2.number != v[arr[s2.row][s2.col]-1].number){
					ch.push_back(pair<int, int>(s2.number, v[(arr[s2.row][s2.col]) - 1].number));
				}
			}
		}
	}
}

int main() {
	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> s >> d >> z;
		shark S(i, r, c, s, d, z);
		v.push_back(S);
		arr[r][c] = i;
	}


	for (int i = 1; i <= C; i++) {
		catchShark(i);
		moveShark();

	}
	printf("%d\n", cnt);

	return 0;
}
*/