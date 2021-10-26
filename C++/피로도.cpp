#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int k, vector<vector<int>> dungeons, int currNode, int depth, vector<bool> &visited, int &answer)
{
	visited[currNode] = true;
	k -= dungeons[currNode][1];

	for (int i = 0; i < dungeons.size(); ++i)
	{
		if (visited[i] == false && dungeons[i][0] <= k)
		{
			dfs(k, dungeons, i, depth + 1, visited, answer);
		}
	}
	answer = max(answer, depth);
	visited[currNode] = false;
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;
	vector<bool> visited(dungeons.size(), false);


	for (int i = 0; i < dungeons.size(); ++i)
	{
		if (dungeons[i][0] <= k)
		{
			dfs(k, dungeons, i, 1, visited, answer);
		}
	}
	return answer;
}