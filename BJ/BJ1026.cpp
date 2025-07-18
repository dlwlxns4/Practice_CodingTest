#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


vector<int> A;
vector<int> B;
int N;

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		B.push_back(num);
	}
}

void Solution()
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int result = 0;
	for (int i = 0; i < N; i++) 
	{
		result += A[i] * B[i];
	}

	cout << result;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	Solution();


}