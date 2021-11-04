#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
	string ar;
	int N;
	char input;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{

		cin >> ar;

		list<char> outPutList;
		list<char>::iterator cursor = outPutList.end();

		list<char> strList(ar.begin(), ar.end());
		for (auto iter = strList.begin(); iter != strList.end(); ++iter)
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