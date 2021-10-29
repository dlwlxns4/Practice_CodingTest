#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> cache;
	cache.reserve(cacheSize);

	if (cacheSize == 0) return answer = cities.size() * 5;

	for (int i = 0; i < cities.size(); i++)
	{
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
	}


	for (int i = 0; i < cities.size(); ++i)
	{
		for (int j = 0; j < cache.capacity(); ++j)
		{

			if (cache[j] == cities[i])
			{
				answer++;


				cache.erase(cache.begin() + j);
				cache.push_back(cities[i]);
				break;
			}
			else if (cache[j] != cities[i] && j == cache.capacity() - 1)
			{
				if (cache.size() < cacheSize)
				{
					cache.push_back(cities[i]);
				}
				else
				{
					cache.erase(cache.begin());
					cache.push_back(cities[i]);
				}
				answer += 5;
				break;
			}
		}
	}


	return answer;
}