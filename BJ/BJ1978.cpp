#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int prime[1001];

void ErastoTenes()
{
	prime[1] = true;
	for (int i = 2; i < 1001; ++i)
	{
		if (prime[i] == true)
		{
			continue;
		}

		for (int j = 2 * i; j < 1001; j += i)
		{
			prime[j] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	int ans = 0;

	cin >> N;

	ErastoTenes();

	for (int i = 0; i < N; ++i)
	{
		int elem;
		cin >> elem;
		if (prime[elem] == false)
		{
			ans++;
		}
	}

	cout << ans;
}
