#include <queue>
#include <stdio.h>

using namespace std;

int main()
{
	int N, M;
	int queue[1'000'000] = {};
	int front = 0;
	int back = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		queue[back++] = i + 1;
	}

	printf("<");
	while (front + 1 != back)
	{
		for (int i = 0; i < M - 1; ++i)
		{
			queue[back++] = queue[front];
			front++;
		}

		printf("%d, ", queue[front++]);
	}
	printf("%d>", queue[front++]);
}