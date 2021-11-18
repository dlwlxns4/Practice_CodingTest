#include <vector>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;
queue<int> q;

bool bfs(const vector<vector<int>>& computers, vector<bool>& isVisited, int n)
{
	bool check = false;
	while (!q.empty())
	{
		int startNode = q.front();
		q.pop();

		for (int i = 0; i < n; ++i)
		{
			if (isVisited[i] == false && computers[startNode][i] == 1)
			{
				q.push(i);
				isVisited[startNode] = true;

			}
		}

	}

	return true;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<bool> isVisited(n, false);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (isVisited[j] == false && computers[i][j] == 1)
			{
				q.push(j);

				isVisited[j] = true;
				if (bfs(computers, isVisited, n))
					answer++;
			}
		}
	}

	return answer;
}