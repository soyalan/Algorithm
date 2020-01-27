#include <iostream>
#include <algorithm>

using namespace std;

int score[10];
int Board[9][9] = {
{0,40,38,-1,36,-1,34,32,30},
{-1,40,-1,-1,-1,-1,-1,28,28},
{-1,-1,35,-1,-1,-1,27,-1,26},
{0,-1,-1,30,0,26,-1,-1,-1},
{2,-1,-1,-1,25,-1,-1,-1,24},
{4,-1,-1,19,-1,24,-1,-1,-1},
{6,-1,16,-1,-1,-1,22,-1,22},
{8,13,-1,-1,-1,-1,-1,-1,-1},
{10,12,14,-1,16,-1,18,-1,20}
};

int res;

pair<int, int> move(pair<int, int> horse, int n) {
	int y = horse.first;
	int x = horse.second;
	int i = 0;

	if (x == 0) {
		if (y == 8) {
			for (i = 0; i < n; i++) {
				if (x == 4) break;
				x++;
				y--;
			}
			for (; i < n; i++) {
				y--;
				x--;
			}
		}

		else {
			for (i = 0; i < n; i++) {
				if (y == 8) {
					x++;
					if (Board[y][x] == -1) x++;
				}
				else y++;
			}
		}

		return { y,x };
	}

	if (y == 8) {

		if (x == 8) {
			for (i = 0; i <= n; i++) {
				x--;
				y--;
			}
		}
		else {
			for (i = 0; i < n; i++) {
				if (x == 8) {
					y--;
					if (Board[y][x] == -1) y--;
				}
				else {
					x++;
					if (Board[y][x] == -1) x++;
				}
			}
		}

		return { y,x };
	}

	if (x == 8) {

		if (y == 0) {
			for (i = 0; i < n; i++) {
				if (x == 4) break;
				y++;
				x--;
			}
			for (; i < n; i++) {
				y--;
				x--;
			}
		}
		else {
			for (i = 0; i < n; i++) {
				if (y == 0) {
					x--;
					if (Board[y][x] == -1) x--;
				}
				else {
					y--;
					if (Board[y][x] == -1) y--;
				}
			}
		}

		return { y,x };
	}

	if (y == 0) {
		for (i = 0; i < n; i++) {
			x--;
			if (Board[y][x] == -1) x--;
			if (x == 0) break;
		}

		return { y,x };
	}



	if (y > 4 && x < 4) {
		for (i = 0; i < n; i++) {
			if (x == 4) break;
			x++;
			y--;
		}
		for (; i < n; i++) {
			x--;
			y--;
		}
	}
	else if (y > 4 && x > 4) {
		for (i = 0; i < n; i++) {
			x--;
			y--;
		}
	}
	else if (y < 4 && x > 4) {
		for (i = 0; i < n; i++) {
			if (x == 4)break;
			x--;
			y++;
		}
		for (; i < n; i++) {
			x--;
			y--;
		}
	}
	else {
		for (i = 0; i < n; i++) {
			x--;
			y--;
			if (x == 0) break;
		}
	}

	return { y,x };
}

void dfs(int cnt, pair<int, int> horse[4], int sum) {
	if (cnt == 10) {
		res = max(sum, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (horse[i].first == 0 && horse[i].second == 0) continue;

		pair<int, int> next = move(horse[i], score[cnt]);
		bool check = true;

		for (int j = 0; j < 4; j++) {
			if (i != j) {
				if (next.first == horse[j].first && next.second == horse[j].second) {
					if (!(next.first == 0 && next.second == 0)) {
						check = false;
						break;
					}
				}

				if (next.first == 0 && next.second == 1) {
					if (horse[j].first == 1 && horse[j].second == 1) {
						check = false;
						break;
					}
				}
				else if (next.first == 1 && next.second == 1) {
					if (horse[j].first == 0 && horse[j].second == 1) {
						check = false;
						break;
					}
				}
			}
		}

		if (check) {
			pair<int, int> temp = horse[i];
			horse[i] = next;
			int get = Board[next.first][next.second];
			dfs(cnt + 1, horse, sum + get);
			horse[i] = temp;
		}
	}
}

int main() {
	pair<int, int> horse[4];

	for (int i = 0; i < 10; i++) cin >> score[i];
	for (int i = 0; i < 4; i++) horse[i] = { 3,0 };

	dfs(0, horse, 0);

	cout << res << "\n";

	return 0;
}