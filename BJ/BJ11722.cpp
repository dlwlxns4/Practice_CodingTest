#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int N;
vector<int> A;
vector<int> Dp;
vector<int> Prev;

void Input();
void Solution();

void Input()
{
	cin >> N;
	A.resize(N);
	Dp.resize(N);
	Prev.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		Dp[i] = 1;
		Prev[i] = -1;
	}
}

void Solution()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (A[i] < A[j])
			{
				Dp[i] = max(Dp[i], Dp[j] + 1);
			}
		}
	}

	cout << *max_element(Dp.begin(), Dp.end());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	Solution();
}