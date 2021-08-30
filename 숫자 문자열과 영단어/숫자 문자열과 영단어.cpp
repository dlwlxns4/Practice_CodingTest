#include <string>
#include <vector>

using namespace std;


int solution(string s) {
    int answer = 0;
    vector<pair<string, string>> num;
    string answerNum = "";

    num.push_back({ "zero","0" });
    num.push_back({ "one","1" });
    num.push_back({ "two","2" });
    num.push_back({ "three","3" });
    num.push_back({ "four","4" });
    num.push_back({ "five","5" });
    num.push_back({ "six","6" });
    num.push_back({ "seven","7" });
    num.push_back({ "eight","8" });
    num.push_back({ "nine","9" });

    string alphabet;
    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            alphabet += ch;
            if (alphabet.size() != 0) {
                for (auto it : num) {
                    if (it.first == alphabet) {
                        alphabet.clear();
                        answerNum += it.second;
                    }
                }
            }
        }
        else {
            if (alphabet.size() != 0) {
                for (auto it : num) {
                    if (it.first == alphabet) {
                        alphabet.clear();
                        answerNum += it.second;
                    }
                }
            }
            answerNum += ch;
        }
    }
    if (answerNum.size() != 0)
        answer = stoi(answerNum);

    return answer;
}