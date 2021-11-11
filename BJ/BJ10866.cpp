#include <stdio.h>
#include <string.h>

using namespace std;


int deque[1'000'000] = { };
int front = 0;
int back = 0;

int main()
{
	int N;

	scanf("%d", &N);
	char input[16] = { 0 };
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", input);
		if (0 == strcmp(input, "push_front"))
		{
			int inputNum = 0;
			scanf("%d", &inputNum);
			for (int i = back; i > front; --i)
			{
				deque[i] = deque[i - 1];
			}
			back++;
			deque[front] = inputNum;
		}
		else if (0 == strcmp(input, "push_back"))
		{
			int inputNum = 0;
			scanf("%d", &inputNum);
			deque[back++] = inputNum;
		}
		else if (0 == strcmp(input, "pop_front"))
		{
			if (back - front == 0)
				printf("-1\n");
			else
				printf("%d\n", deque[front++]);
		}
		else if (0 == strcmp(input, "pop_back"))
		{
			if (back - front == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", deque[(back)-1]);
				back--;
			}
		}
		else if (0 == strcmp(input, "size"))
		{
			printf("%d\n", back - front);
		}
		else if (0 == strcmp(input, "empty"))
		{
			if (back - front == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (0 == strcmp(input, "front"))
		{
			if (back - front == 0)
				printf("-1\n");
			else
				printf("%d\n", deque[front]);
		}
		else if (0 == strcmp(input, "back"))
		{
			if (back - front == 0)
				printf("-1\n");
			else
				printf("%d\n", deque[back - 1]);
		}

	}

}