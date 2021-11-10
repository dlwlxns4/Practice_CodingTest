//#include <iostream>
//#include <stack>
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
//	int input;
//	int N;
//	int sum = 0;
//
//	cin >> N;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> input;
//		if (input == 0)
//		{
//			if (!stk.empty())
//				stk.pop();
//		}
//		else
//		{
//			stk.push(input);
//		}
//	}
//
//	while (!stk.empty())
//	{
//		sum += stk.top();
//		stk.pop();
//	}
//	cout << sum;
//}