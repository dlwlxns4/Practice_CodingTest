#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		long long from, to;
		cin >> from >> to;

		long long count = 1;
		long long length = to - from;
		long long currPos = 1;
		long long jumpDistance = 0;
		while (true)
		{
			jumpDistance++;

			count++;
			currPos += jumpDistance;
			if (currPos >= length)
			{
				break;
			}

			count++;
			currPos += jumpDistance;
			if (currPos >= length)
			{
				break;
			}


		}
		if (currPos > length)
		{
			count--;
		}
		cout << count << endl;;
	}
}
