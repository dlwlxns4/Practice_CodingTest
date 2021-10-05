#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	map<char, int> skill_count;
	for (int i = 0; i < skill.size(); i++)
		skill_count[skill[i]] = i + 1;


	for (int i = 0; i < skill_trees.size(); i++)
	{
		int count = 1;
		bool check = true;
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			if (skill_count[skill_trees[i][j]] > count)
			{
				check = false;
				break;
			}
			else if (skill_count[skill_trees[i][j]] == count)
				count++;
		}
		if (check)
			answer++;
	}

