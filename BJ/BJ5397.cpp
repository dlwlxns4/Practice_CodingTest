#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	string ar;
	int N;
	char input;

	cin >> N;
	for (int i = 0; i < N; i++)
	{

		cin >> ar;

		list<char> outPutList;
		list<char>::iterator cursor = outPutList.end();

		for (auto iter = ar.begin(); iter != ar.end(); ++iter)
		{
			switch (*iter)
			{
			case '<':
				if (cursor != outPutList.begin())
				{
					cursor--;
				}
				break;
			case '>':
				if (cursor != outPutList.end())
				{
					cursor++;
				}
				break;
			case '-':
				if (cursor != outPutList.begin())
				{
					cursor--;
					cursor = outPutList.erase(cursor);
				}
				break;
			default:
				outPutList.insert(cursor, *iter);
				break;
			}
		}
		for (auto ch : outPutList)
			cout << ch;
		cout << endl;
	}


}