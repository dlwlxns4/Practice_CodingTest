#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;

int BinarySearch(const vector<long long>& vec)
{
	long long start = 1'000'000'000;
	long long mid = 0;
	for (int i = 1; i < vec.size(); ++i)
	{
		start = min(start, (vec[i] - vec[i - 1]));
	}
	long long end = vec.back() - vec.front();


	mid = (start + end) / 2;
	while (start <= end)
	{
		long long count = 1;

		int router = vec.front();
		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] - router >= mid)
			{
				count++;
				router = vec[i];
			}
		}

		if (count >= M)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;

	}

	return mid;
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