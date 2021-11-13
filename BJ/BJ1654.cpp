#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;

int BinarySearch(const vector<long long>& vec)
{
	long long start = 1;
	long long end = vec.back();
	long long mid = 0;
	long long answer = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int count = 0;

		for (int i = 0; i < vec.size(); ++i)
		{
			count += vec[i] / mid;
		}

		if (count >= M)
		{
			if (answer < mid)
			{
				answer = mid;
			}
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<long long> vec;

	cin >> N;
	cin >> M;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}
	sort(vec.begin(), vec.end());

	cout << BinarySearch(vec);
}