#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map<string, int> hash;

	for (auto str : phone_book)
		hash[str]++;

	for (int i = 0; i < phone_book.size(); i++) {
		string phone_num = "";
		for (int j = 0; j < phone_book[i].size(); j++) {
			phone_num += phone_book[i][j];

			if (hash[phone_num] && phone_num != phone_book[i])
				return answer = false;
		}
	}



	return answer;
}