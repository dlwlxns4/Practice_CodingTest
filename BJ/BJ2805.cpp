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

		long long sum = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] > mid)
			{
				sum += vec[i] - mid;
			}

		}
		if (sum >= M)
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