#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N, M;

	int* q;
	string func;
	string ar;

	cin >> N;

	if (N == 0)
	{
		cout << "[]\n";
	}
	else
		for (int i = 0; i < N; ++i)
		{
			cin >> func;
			cin >> M;
			cin >> ar;

			vector<int> q(M);
			int index = 0;
			string num;
			if (M > 0)
			{
				for (int i = 1; i <= ar.size() - 1; ++i)
				{
					if (ar[i] == ',' || i >= ar.size() - 1)
					{
						q[index++] = stoi(num);
						num.clear();
						continue;
					}
					num += ar[i];
				}
			}



			int start = 0, end = M;
			bool isReverse = false;
			bool isError = false;
			int dCount = 0;
			for (int i = 0; i < func.size(); ++i)
			{
				if (func[i] == 'R')
				{
					isReverse = isReverse == false ? true : false;
				}
				else
				{
					dCount++;
					if (isReverse)
					{
						end--;
					}
					else
					{
						start++;
					}
				}

				if (dCount > M)
				{
					isError = true;
					break;
				}
			}


			if (isError)
			{
				cout << "error\n";
				continue;
			}
			else
			{
				if (isReverse)
				{
					cout << "[";
					for (int i = end - 1; i >= start; i--)
					{
						if (i != start)
						{
							cout << q[i] << ",";
						}
						else
						{
							cout << q[i];
						}
					}
					cout << "]\n";
				}
				else
				{
					cout << "[";
					for (int i = start; i <= end - 1; i++)
					{
						if (i != end - 1)
						{
							cout << q[i] << ",";
						}
						else
						{
							cout << q[i];
						}
					}
					cout << "]\n";
				}
			}

		}
}