#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int V, E;
int K;
vector<vector<int>> graph;
vector<int> color;


void Input();
bool BFS(int startNode);

void Input()
{
	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		cin >> V >> E;

		graph.assign(V + 1, vector<int>());
		color.assign(V + 1, 0);

		for(int j=0; j<E; ++j)
		{
			int u, v;
			cin >> u >> v;
			
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool isBipartite = true;
		for(int j=1; j<=V; ++j)
		{
			if (color[j] == 0)
			{
				isBipartite = BFS(j);
				if (isBipartite == false)
					break;
			}
		}

		cout << (isBipartite ? "YES\n" : "NO\n");
	}
}



bool BFS(int startNode)
{
	queue<int> q;
	q.push(startNode);
	color[startNode] = 1;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int next : graph[current])
		{
			if (color[next] == 0)
			{
				color[next] = -color[current];
				q.push(next);
			}
			else if (color[next] == color[current])
			{
				return false;
			}
		}
	}
	
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
}