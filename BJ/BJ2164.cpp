#include <queue>
#include <stdio.h>

using namespace std;

int main()
{
	int N;
	queue<int> q;

	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		q.push(i);
	}

	int state = 0;
	while (q.size() != 1)
	{
		if (state == 0)
		{
			q.pop();
			state++;
		}
		else if (state == 1)
		{
			q.push(q.front());
			q.pop();
			state--;
		}
	}
	printf("%d", q.front());
}