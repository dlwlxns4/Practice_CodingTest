#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, x = -1, lenght = -1;
	cin >> N >> M;

	for (int i = M; i < 101; ++i)
	{
		int t = (i - 1) * i / 2;
		if ((N - t) % i == 0 & (N - t) / i >= 0)
		{
			x = (N - t) / i;
			lenght = i;
			break;
		}
	}

	if (x == -1)
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i < lenght; ++i)
		{
			cout << x + i << " ";
		}
	}
}