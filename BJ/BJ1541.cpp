#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string formula;

	cin >> formula;

	bool isMinus = false;


	string num;
	int answer = 0;
	for (int i = 0; i <= formula.size(); ++i)
	{
		if (formula[i] == '-' || formula[i] == '+' || i == formula.size())
		{
			if (isMinus)
			{
				answer -= stoi(num);
			}
			else
			{
				answer += stoi(num);
			}
			num.clear();
		}
		else
		{
			num += formula[i];
		}

		if (formula[i] == '-')
		{
			isMinus = true;
		}

	}


	cout << answer;

}