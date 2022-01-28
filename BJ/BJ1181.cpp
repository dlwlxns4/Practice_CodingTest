#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int N;
	cin >> N;
	vector<int> arr;

	for (int i = 0; i < N; ++i)
	{
		int elem;
		cin >> elem;
		arr.push_back(elem);
	}
	sort(arr.begin(), arr.end());

	for (int i = 2; i <= arr[0]; ++i)
	{

	}
}