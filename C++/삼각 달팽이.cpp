#include <string>
#include <vector>


using namespace std;

vector<int> solution(int n) {
	vector<int> answer;

	int ar[1000][1000] = { 0 };
	enum Dir { DOWN, RIGHT, UP };
	int x = 0, y = 0;
	int num = 1;
	Dir dir = Dir::DOWN;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			switch (dir) {
			case Dir::DOWN:
				ar[x++][y] = num++;
				break;
			case Dir::UP:
				ar[x--][y--] = num++;
				break;
			case Dir::RIGHT:

				ar[x][y++] = num++;
				break;
			}
		}
		if (dir == Dir::DOWN) {
			dir = Dir::RIGHT;
			x--;
			y++;
		}
		else if (dir == Dir::RIGHT) {
			dir = Dir::UP;
			x--;
			y -= 2;
		}
		else if (dir == Dir::UP) {
			dir = Dir::DOWN;
			x += 2;
			y++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ar[i][j] != 0) {
				answer.push_back(ar[i][j]);
			}
		}
	}


	return answer;
}