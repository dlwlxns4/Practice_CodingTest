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
//	stack<int> stk;
//	string input;
//	int N;
//
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> input;
//		if (input == "push")
//		{
//			int inputNum;
//			cin >> inputNum;
//
//			stk.push(inputNum);
//		}
//		else if (input == "top")
//		{
//			if (stk.empty())
//				cout << -1 << endl;
//			else
//				cout << stk.top() << endl;
//		}
//		else if (input == "size")
//		{
//			cout << stk.size() << endl;
//		}
//		else if (input == "pop")
//		{
//			if (stk.empty())
//				cout << -1 << endl;
//			else
//			{
//				cout << stk.top() << endl;
//				stk.pop();
//			}
//		}
//		else if (input == "empty")
//		{
//			if (stk.empty())
//				cout << 1 << endl;
//			else
//				cout << 0 << endl;
//		}
//	}
//}