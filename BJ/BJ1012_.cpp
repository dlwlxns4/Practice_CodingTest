#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int T;
int M, N, K;
int X, Y;

vector<vector<int>> map;
vector<vector<bool>> isVisited;

void Solution();
void Input();
void DFS(int x, int y);
void Answer();

void Input()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		map = vector<vector<int>>(N, vector<int>(M, 0));
		isVisited = vector<vector<bool>>(N, vector<bool>(M, false));

		for (int j = 0; j < K; ++j)
		{
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		Solution();
	}
}

void DFS(int y, int x)
{
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	stack<pair<int, int>> stk;
	stk.push({ x, y });

	while (!stk.empty())
	{
		pair<int, int> pos = stk.top();
		stk.pop();
		
		if (isVisited[pos.second][pos.first])
			continue;

		isVisited[pos.second][pos.first] = true;
		for(int i=0; i < 4; ++i)
		{
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;

			if (map[ny][nx] == 1 && isVisited[ny][nx] == false)
			{
				stk.push({ nx, ny });
			}
		}
	}
}

void Solution()
{
	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 1 && isVisited[i][j] == false)
			{
				DFS(i, j);
				answer++;
			}
		}
	}
	cout << answer << endl;
}



void Answer()
{
	Input();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Answer();
}