#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int x1, y1, x2, y2;
		int answer = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		int planetCount;
		cin >> planetCount;

		for (int j = 0; j < planetCount; ++j)
		{
			int x, y, r;
			cin >> x >> y >> r;

			if (pow(x - x1, 2) + pow(y - y1, 2) < pow(r, 2))
			{
				if (pow(x - x2, 2) + pow(y - y2, 2) > pow(r, 2))
				{
					answer++; // �ȿ��� ������ ���� ���� ���̽�
				}
			}

			if (pow(x - x1, 2) + pow(y - y1, 2) > pow(r, 2))
			{
				if (pow(x - x2, 2) + pow(y - y2, 2) < pow(r, 2))
				{
					answer++; // �ۿ��� ������ ���� ���� ���̽�
				}
			}
		}
		cout << answer << "\n";
	}
}