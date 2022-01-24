#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	vector<int> coins;
	int answer = 0;

	cin >> N >> K;


	for (int i = 0; i < N; ++i)
	{
		int worth;
		cin >> worth;
		coins.push_back(worth);
	}
	int total = 0, index = N - 1;
	while (K != 0)
	{
		if (coins[index] > K)
		{
			index--;
		}
		else
		{
			answer++;
			K -= coins[index];
		}
	}
	cout << answer;
}