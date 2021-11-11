#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int N = 0;
	queue<int> q;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string input = "";
		cin >> input;

		if (input == "push")
		{
			int inputNum = 0;
			cin >> inputNum;
			q.push(inputNum);
		}
		else if (input == "pop")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (input == "size")
		{
			cout << q.size() << "\n";
		}
		else if (input == "empty")
		{
			if (q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (input == "front")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (input == "back")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}
	}
}