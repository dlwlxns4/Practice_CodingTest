#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> usedWords;
    int nIndex = 2, turn = 1;

    for (int i = 1; i < words.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (words[i] == words[j]) {
                answer.push_back(nIndex);
                answer.push_back(turn);
                return answer;
            }
        }

        if (words[i][0] != words[i - 1][words[i - 1].size() - 1]) {
            answer.push_back(nIndex);
            answer.push_back(turn);
            return answer;
        }

        nIndex++;

        if (nIndex == n + 1) {
            nIndex = 1; turn++;
        }

        if (i == words.size() - 1) {
            answer.push_back(0);
            answer.push_back(0);
            return answer;
        }
    }
}