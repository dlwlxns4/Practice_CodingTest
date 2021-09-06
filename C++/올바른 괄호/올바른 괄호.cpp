#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	bool answer = false;
	stack<char> stk;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stk.push(s[i]);
			continue;
		}
		else if (s[i] == ')' && !stk.empty()) {
			if (stk.top() == '(' && s[i] == ')')
				stk.pop();
		}
		else if (s[i] == ')' && stk.empty()) {
			return answer = false;
		}
	}

	if (stk.empty())
		answer = true;



	return answer;
}