#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	vector<int> distances;
	vector<int> prices;

	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int distance;
		cin >> distance;
		distances.push_back(distance);
	}
	for (int i = 0; i < N; ++i)
	{
		int price;
		cin >> price;
		prices.push_back(price);
	}

	long long currPrice = prices[0];
	long long answer = currPrice * distances[0];

	for (int i = 1; i < N - 1; ++i)
	{
		if (currPrice > prices[i])
		{
			currPrice = prices[i];
			answer += currPrice * distances[i];
		}
		else
		{
			answer += currPrice * distances[i];
		}
	}
	cout << answer;
}