#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INF 987654321
int N, M;

void BFS(vector<vector<int>>& map, vector<vector<int>>& dist)
{
	queue<pair<int, int>> q;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	dist[0][0] = 0;
	q.emplace(0, 0);


	while (q.empty() == false)
	{
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newPosX = pos.second + dx[i];
			int newPosY = pos.first + dy[i];

			if (newPosX < 0 || newPosX >= N || newPosY < 0 || newPosY >= M)
			{
				continue;
			}

			if (map[newPosY][newPosX] == '1')
			{
				if (dist[newPosY][newPosX] > dist[pos.first][pos.second] + 1)
				{
					dist[newPosY][newPosX] = dist[pos.first][pos.second] + 1;
					q.emplace(newPosY, newPosX);
				}
			}
			else if (map[newPosY][newPosX] == '0')
			{
				if (dist[newPosY][newPosX] > dist[pos.first][pos.second])
				{
					dist[newPosY][newPosX] = dist[pos.first][pos.second];
					q.emplace(newPosY, newPosX);
				}
			}
		}
	}


}

int main()
{
	cin >> N >> M;
	vector<vector<int>> map;
	vector<vector<int>> dist;


	for (int i = 0; i < M; ++i)
	{
		vector<int> tmp;
		vector<int> tmpDist;
		for (int j = 0; j < N; ++j)
		{
			char mapInfo;
			cin >> mapInfo;

			tmp.push_back((mapInfo));
			tmpDist.push_back(INF);
		}
		map.push_back(tmp);
		dist.push_back(tmpDist);
	}

	BFS(map, dist);


	cout << dist[M - 1][N - 1];
}