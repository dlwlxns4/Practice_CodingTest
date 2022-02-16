#pragma warning(disable:4996)

#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

#define INF 987'654'321

int computerCount;
int N;

void GetShortestPath(vector<vector<pair<int, int>>>& graph, int startNode, int& infectCount, int& MAX)
{
	vector<int> dist(computerCount + 1, INF);
	vector<int> isVisited(computerCount + 1, false);

	dist[startNode] = 0;

	priority_queue<pair<int, int>> pq;
	pq.emplace(startNode, 0);
	isVisited[startNode] = true;

	while (false == pq.empty())
	{
		int vertex = pq.top().first;
		int weight = -pq.top().second;

		pq.pop();

		for (pair<int, int> i : graph[vertex])
		{
			if (dist[i.first] > dist[vertex] + i.second)
			{
				dist[i.first] = dist[vertex] + i.second;

				pq.emplace(i.first, -dist[i.first]);
			}
		}
	}

	for (int i = 0; i < dist.size(); ++i)
	{
		if (dist[i] != INF)
		{
			infectCount++;
			if (MAX < dist[i])
				MAX = dist[i];
		}
	}
}

int main()
{

	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		int dependencyCount, firstInfect;
		scanf("%d %d %d", &computerCount, &dependencyCount, &firstInfect);

		int infectCount = 0;
		int MAX = 0;

		vector<vector<pair<int, int>>> graph(computerCount + 1);
		for (int i = 0; i < dependencyCount; ++i)
		{
			int start, end, second;
			scanf("%d %d %d", &start, &end, &second);
			graph[end].emplace_back(start, second);
		}

		GetShortestPath(graph, firstInfect, infectCount, MAX);


		printf("%d %d\n", infectCount, MAX);
	}
}