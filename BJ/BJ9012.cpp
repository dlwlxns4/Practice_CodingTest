//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	std::ios_base::sync_with_stdio(false);
//	std::cout.tie(nullptr);
//	std::cin.tie(nullptr);
//
//	string input;
//	int N;
//
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		stack<char> stk;
//		cin >> input;
//		for (auto iter = input.begin(); iter != input.end(); ++iter)
//		{
//			if (*iter == '(')
//			{
//				stk.push(*iter);
//			}
//			else if (*iter == ')')
//			{
//				if (stk.empty())
//				{
//					stk.push(')');
//					continue;
//				}
//
//				if (stk.top() == '(')
//					stk.pop();
//				else
//					stk.push(*iter);
//			}
//		}
//
//		if (stk.empty())
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//
//	}
//}