#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int x, count = 0;
	cin >> x;

	while (x > 0)
	{
		if (x % 2 == 1)
		{
			count++;
		}
		x /= 2;
		cout << x << endl;
	}
	cout << count;
}