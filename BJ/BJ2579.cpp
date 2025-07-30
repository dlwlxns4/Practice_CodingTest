#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int N;
vector<int> Point;
vector<int> dp;

void Input();
void Solution();

void Input()
{
	cin >> N;

	dp.assign(N, 0);
	for (int i = 0; i < N; ++i)
	{
		int point;
		cin >> point;
		Point.push_back(point);
	}
}

void Solution()
{
	dp[0] = Point[0];
	
	if (N >= 2)
	{
		dp[1] = Point[0] + Point[1];
	}

	if (N >= 3)
	{
		dp[2] = max(Point[0] + Point[2], Point[1] + Point[2]);
	}

	for (int i = 3; i < N; ++i)
	{
		dp[i] = max(dp[i-2] + Point[i], dp[i - 3] + Point[i - 1] + Point[i]);
	}

	cout << dp[N - 1] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	Solution();
}