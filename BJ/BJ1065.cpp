#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;

	cin >> N;

	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (i < 100)
		{
			ans++;
			continue;
		}
		int num = i;
		int a1 = num % 10;
		int a2 = num % 100 / 10;
		int a3 = num / 100;

		if (a3 - a2 == a2 - a1)
		{
			ans++;
		}
	}

	cout << ans;
}
