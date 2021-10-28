#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int num = 0;
	bool check = false;

	for (int i = 0; i < number.size() - 1; i++)
	{
		if (number[i] < number[i + 1])
		{
			number.erase(number.begin() + i);
			num++;
			i = -1;
		}
		if (num == k) {
			check = true;
			break;
		}

	}
	while (num != k)
	{
		char min = number[0];
		int index = 0;
		for (int i = 1; i < number.size(); i++)
		{
			if (min > number[i])
			{
				min = number[i];
				index = i;
			}
		}
		number.erase(number.begin() + index);
		num++;
	}


	return answer = number;
}