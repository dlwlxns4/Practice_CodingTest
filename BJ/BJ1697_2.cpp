#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int N;
int K;
vector<int> dist(100001, -1);


void Solution();
void Input();
void BFS();

void Input()
{
	cin >> N >> K;
}


void Solution()
{
	BFS();
}

void BFS()
{
	queue<int> q;

	q.push(N);
	dist[N] = 0;

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		if (pos == K)
		{
			cout << dist[pos];
			return;
		}


		int nextPos[3] = { pos - 1, pos + 1, pos * 2 };

		for (int i = 0; i < 3; ++i)
		{
			int next = nextPos[i];
			if(next < 0 || next >= 100'001 || dist[next] != -1)
				continue;

			dist[next] = dist[pos] + 1;
			q.push(next);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	Solution();
}