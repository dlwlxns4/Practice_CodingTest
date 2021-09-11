#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> hash;

	for (auto str : participant)
		hash[str]++;

	for (auto str : completion)
		hash[str]--;

	for (auto pair : hash)
		if (pair.second == 1)
			return pair.first;

	return answer;
}