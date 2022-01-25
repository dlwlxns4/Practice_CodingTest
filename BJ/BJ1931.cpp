#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return  a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	int N;
	vector<pair<int, int>> times;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int in, out;
		cin >> in >> out;

		times.emplace_back(in, out);
	}
	sort(times.begin(), times.end(), cmp);

	int now = times[0].second;
	int answer = 1;

	for (int i = 1; i < N; ++i)
	{
		if (now <= times[i].first)
		{
			answer++;
			now = times[i].second;

		}
	}

	cout << answer;
}