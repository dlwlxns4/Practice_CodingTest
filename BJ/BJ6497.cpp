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

	if (a == b) //�θ� ����
		return true;
	else  //�θ� �ٸ�
		return false;
}


int main() {
	int N, M;

	cin >> N >> M;

	while (N != 0 && M != 0)
	{

		vector<Edge> graph;
		int total = 0;
		for (int i = 0; i < M; ++i)
		{
			int start, end, distance;
			cin >> start >> end >> distance;
			graph.push_back(Edge(start, end, distance));
			total += distance;
		}


		vector<int> parent(N);
		for (int i = 0; i < N; ++i)
		{
			parent[i] = i;
		}

		int sum = 0;

		sort(graph.begin(), graph.end());

		for (int i = 0; i < graph.size(); ++i)
		{
			if (FindParent(parent, graph[i].node[0], graph[i].node[1]) == false)
			{
				sum += graph[i].distance;
				UnionParent(parent, graph[i].node[0], graph[i].node[1]);
			}
		}

		cout << total - sum << "\n";
		cin >> N >> M;
	}
}