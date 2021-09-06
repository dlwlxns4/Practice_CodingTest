#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> stack;

    for (int i = 0; i < s.size(); i++) {
        if (stack.empty() || stack.top() != s[i])
            stack.push(s[i]);
        else if (stack.top() == s[i]) {
            stack.pop();
        }
    }

    if (stack.empty())
        answer++;


    return answer;
}