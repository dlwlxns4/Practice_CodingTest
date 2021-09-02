#include <string>
#include <vector>
#include <stack>

using namespace std;

bool IsOpen(char ch) {
    if (ch == '[' || ch == '{' || ch == '(')
        return true;

    return false;
}

bool IsClose(stack<char>& stk, char ch) {
    if (stk.empty())
        return false;
    else {
        if (stk.top() == '[' && ch == ']') {
            stk.pop();
            return true;
        }
        else if (stk.top() == '{' && ch == '}') {
            stk.pop();
            return true;
        }
        else if (stk.top() == '(' && ch == ')') {
            stk.pop();
            return true;
        }
    }

    return false;
}

int solution(string s) {
    int answer = 0;
    stack<char> stk;
    string tmp = s;

    for (int j = 0; j < tmp.size() - 1; j++) {

        bool isPop;
        while (!stk.empty()) stk.pop();


        for (int i = 0; i < tmp.size(); i++) {
            if (IsOpen(tmp[i])) {
                stk.push(tmp[i]);
            }
            else {
                isPop = IsClose(stk, tmp[i]);
                if (!isPop)
                    break;
            }
        }
        if (stk.empty() && isPop)
            answer++;


        tmp.clear();
        tmp += s.substr(j + 1, s.size());
        tmp += s.substr(0, j + 1);

        // s.erase(s);

    }

    return answer;
}