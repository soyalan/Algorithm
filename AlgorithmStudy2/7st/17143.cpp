#include <iostream>
#include <vector>

using namespace std;

class Shark {
public:
	int y, x;
	int size, speed, dir;
	bool life;

	Shark(int y, int x, int size, int speed, int dir) {
		this->y = y;
		this->x = x;
		this->size = size;
		this->speed = speed;
		this->dir = dir;
		life = true;
	}
};

int width, height, M;
int map[101][101];
vector<Shark> shark;
int res;

void fish(int n) {
	for (int i = 1; i <= height; i++) {
		if (map[i][n]) {
			shark[map[i][n]].life = false;
			res += shark[map[i][n]].size;
			map[i][n] = 0;
			return;
		}
	}
}

void move() {
	for (int i = 1; i <= M; i++) {
		if (shark[i].life) {
			int y = shark[i].y;
			int x = shark[i].x;
			if(map[y][x] == i) map[y][x] = 0;

			int dis = shark[i].speed;
			while (dis > 0) {
				if (shark[i].dir == 1) { // up
					y--;
					if (y == 1) shark[i].dir = 2;
				}
				else if (shark[i].dir == 2) { // down
					y++;
					if (y == height) shark[i].dir = 1;
				}
				else if (shark[i].dir == 3) { // right
					x++;
					if (x == width) shark[i].dir = 4;
				}
				else { // left
					x--;
					if (x == 1) shark[i].dir = 3;
				}
				dis--;
			}

			if (map[y][x]) {
				int prev = map[y][x];
				if (prev < i) {
					if (shark[prev].size < shark[i].size) {
						shark[prev].life = false;
						shark[i].y = y;
						shark[i].x = x;
						map[y][x] = i;
					}
					else {
						shark[i].life = false;
					}
				}
				else {
					map[y][x] = i;
					shark[i].y = y;
					shark[i].x = x;
				}
			}
			else {
				shark[i].y = y;
				shark[i].x = x;
				map[y][x] = i;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> height >> width >> M;
	shark.push_back({ 0,0,0,0,0 });

	for (int i = 1; i <= M; i++) {
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		map[y][x] = i;
		if (y == 1 && d == 1) d = 2;
		if (y == height && d == 2) d = 1;
		if (x == 1 && d == 4) d = 3;
		if (x == width && d == 3) d = 4;
		shark.push_back({ y,x,z,s,d });
	}

	for (int i = 1; i <= width; i++) {
		fish(i);
		move();
	}

	cout << res << "\n";

	return 0;
}