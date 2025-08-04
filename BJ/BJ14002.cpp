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
	int maxLen = 0;
	int lastIdx = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (A[j] < A[i] && Dp[i] < Dp[j] + 1)
			{
				Dp[i] = Dp[j] + 1;
				Prev[i] = j;
			}
		}

		if (Dp[i] > maxLen) 
		{
			maxLen = Dp[i];
			lastIdx = i;
		}

	}

	vector<int> result;
	for (int cur = lastIdx; cur != -1; cur = Prev[cur]) 
	{
		result.push_back(A[cur]);
	}

	reverse(result.begin(), result.end());

	cout << result.size() << "\n";
	for(auto index : result)
	{
		cout << index << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	Solution();
}