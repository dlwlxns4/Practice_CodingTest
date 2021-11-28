#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int left = 0, right = people.size() - 1;

	sort(people.begin(), people.end());


	//50 50 70 80 
	while (left <= right)
	{
		if (people[left] + people[right] <= limit)
		{
			left++;
			right--;
		}
		else
		{
			right--;
		}
		answer++;
	}


	return answer;
}