#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> isVisited;
int N;

int answer = 0;

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	while (q.empty() == false)
	{
		pair<int, int> pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int posX = pos.first + dx[i];
			int posY = pos.second + dy[i];

			if (posX >= 0 && posX < N && posY >= 0 && posY < N)
			{
				if (isVisited[posX][posY] == false)
				{
					isVisited[posX][posY] = true;
					q.push({ posX,posY });
				}
			}
		}
	}
}

int main()
{
	cin >> N;

	int minHeight = 0;
	int maxHeight = 1;

	for (int i = 0; i < N; ++i)
	{
		vector<int> mapTmp;
		vector<bool> visitedTmp;
		for (int j = 0; j < N; ++j)
		{
			int height;
			cin >> height;
			mapTmp.push_back(height);
			visitedTmp.push_back(false);
			maxHeight = max(maxHeight, height);
		}
		map.push_back(mapTmp);
		isVisited.push_back(visitedTmp);
	}

	for (int i = minHeight; i <= maxHeight; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				if (i >= map[j][k])
				{
					isVisited[j][k] = true;
				}
			}
		}
		//BFS
		int n = 0;
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				if (isVisited[j][k] == false)
				{
					isVisited[j][k] = true;
					BFS(j, k);
					n++;
				}
			}
		}
		answer = max(answer, n);


		//Init
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				isVisited[j][k] = false;
			}
		}
	}

	cout << answer;
}

