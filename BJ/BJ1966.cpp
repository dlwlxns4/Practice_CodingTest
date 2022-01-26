#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		int num, index;
		cin >> num >> index;

		for (int j = 0; j < num; ++j)
		{
			int elem;
			cin >> elem;
			q.emplace(elem, j);
			pq.push(elem);
		}

		int answer = 0;
		while (!q.empty())
		{
			if (q.front().first == pq.top())
			{
				if (q.front().second == index)
				{
					answer++;
					break;
				}
				else
				{
					q.pop();
					pq.pop();
					answer++;
				}
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
		cout << answer << "\n";
	}
}