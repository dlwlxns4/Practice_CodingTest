#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {
		string cmp = "";
		for (int j = 0; j < skill_trees[i].size(); j++) {
			for (int k = 0; k < skill.size(); k++)
			{
				if (skill[k] == skill_trees[i][j])
				{
					cmp.push_back(skill_trees[i][j]);
				}
			}
		}

		bool check = true;
		for (int i = 0; i < cmp.size(); i++)
		{
			if (skill[i] != cmp[i])
			{
				check = false;
				break;
			}
		}
		if (check)
			answer++;
	}

	return answer;
}