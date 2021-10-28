#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;

	while (left <= right)
	{
		if ((left / n) >= left % n)
		{
			answer.push_back(left / n + 1);
			left++;
			continue;
		}

		answer.push_back(left / n + 1 + (left%n - left / n));
		left++;
	}


	return answer;
}