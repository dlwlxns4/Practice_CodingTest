#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> cloth;

	for (int i = 0; i < clothes.size(); i++)
	{
		cloth[clothes[i][1]] += 1;
	}

	for (auto it = cloth.begin(); it != cloth.end(); ++it)
	{
		answer *= (it->second + 1);
	}

	return answer - 1;
}