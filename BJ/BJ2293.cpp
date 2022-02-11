#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
vector<int> coins;
int ans = 0;




int main()
{
	cin >> N >> K;
	vector<int> dp(K + 1);
	for (int i = 0; i < N; ++i)
	{
		int worth;
		cin >> worth;
		coins.push_back(worth);
	}
	dp[0] = 1;
	for (int i = 0; i < coins.size(); ++i)
	{
		for (int j = coins[i]; j <= K; ++j)
		{
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}
	cout << dp[K];
}