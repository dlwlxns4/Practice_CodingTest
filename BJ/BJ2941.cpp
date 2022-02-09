#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;




int main()
{
	string str;
	vector<string> find_str{ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	cin >> str;


	for (int i = 0; i < find_str.size(); ++i)
	{
		while (1)
		{
			int idx = str.find(find_str[i]);
			if (idx == str.npos)
			{
				break;
			}
			str.replace(idx, find_str[i].size(), "X");
		}
	}

	cout << str.size();

}