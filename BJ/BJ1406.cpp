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
	
	cin >> ar;
	list<char> strList(ar.begin(), ar.end());
	int cursor = ar.size();


	cin >> N;
	for (int i = 0; i < N; i++)
	{

		cin >> input;
		//for (auto ch : strList)
		//	cout << ch;
		//cout << endl;
		
		switch (input)
		{
		case 'L':
			if(cursor>0)
				cursor--;
			break;
		case 'D':
			if(cursor < ar.size())
				cursor++;
			break;
		case 'B':
			if (cursor!=0)
			{
				cursor--;
				strList.erase(strList.begin()+cursor);
				cursor++;
			}
			break;
		case 'P':
			char inputChar;
			cin >> inputChar;
			
			strList.insert(strList+cursor, inputChar);
			break;

		}

		//for (auto ch : strList)
		//	cout << ch;
		//cout << endl;
		
	}

	for (auto ch : strList)
	{
		cout << ch;
	}
}