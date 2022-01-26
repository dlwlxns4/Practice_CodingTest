#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<int> ar;

	cin >> N;


	for (int i = 0; i < N; ++i)
	{
		int elem;
		cin >> elem;
		ar.push_back(elem);
	}

	stack<int> stk2;
	stack<int> answer;

	for (int i = ar.size() - 1; i >= 0; --i)
	{
		while (!stk2.empty() && stk2.top() <= ar[i])
		{
			stk2.pop();
		}

		if (stk2.empty())
		{
			answer.push(-1);
		}
		else
		{
			answer.push(stk2.top());
		}

		stk2.push(ar[i]);
	}

	while (answer.empty() == false)
	{
		cout << answer.top() << " ";
		answer.pop();
	}
}