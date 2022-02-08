#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;




int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int d = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		int min = pow(r1 - r2, 2);
		int max = pow(r1 + r2, 2);

		if (d == 0)
		{
			if (min == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}

		}
		else if (d == max || d == min)
		{
			cout << "1" << "\n";
		}
		else if (min < d && d < max)
		{
			cout << "2" << "\n";
		}
		else
		{
			cout << "0" << "\n";
		}
	}


}