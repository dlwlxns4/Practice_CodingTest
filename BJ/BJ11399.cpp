#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	vector<int> times;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int time;
		cin >> time;
		times.push_back(time);
	}

	sort(times.begin(), times.end());

	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			answer += times[j];
		}
	}

	cout << answer;
}