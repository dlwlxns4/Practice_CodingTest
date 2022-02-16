#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator < (Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

int GetParent(vector<int>& parent, int x)
{
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent, parent[x]);
}

void UnionParent(vector<int>& parent, int a, int b)
{
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool FindParent(vector<int>& parent, int a, int b)
{
	a = GetParent(parent, a);
	b = GetParent(parent, b);

	if (a == b) //부모 같음
		return true;
	else  //부모 다름
		return false;
}


int main() {
	int N, M;

	cin >> N >> M;

	vector<Edge> graph;
	for (int i = 0; i < M; ++i)
	{
		int start, end, distance;
		cin >> start >> end >> distance;
		graph.push_back(Edge(start, end, distance));
	}


	vector<int> parent(N);
	for (int i = 0; i < N; ++i)
	{
		parent[i] = i;
	}

	int sum = 0;

	sort(graph.begin(), graph.end());

	int maxDistance = 0;
	for (int i = 0; i < graph.size(); ++i)
	{
		if (FindParent(parent, graph[i].node[0] - 1, graph[i].node[1] - 1) == false)
		{
			sum += graph[i].distance;
			maxDistance = max(maxDistance, graph[i].distance);
			UnionParent(parent, graph[i].node[0] - 1, graph[i].node[1] - 1);
		}
	}

	cout << sum - maxDistance;
}