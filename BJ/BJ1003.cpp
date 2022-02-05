#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	pair<int, int> count[41];

	count[0] = { 1,0 };
	count[1] = { 0,1 };

	for (int i = 2; i < 41; ++i)
	{
		count[i] = { count[i - 1].first + count[i - 2].first, count[i - 1].second + count[i - 2].second };
	}

	for (int i = 0; i < N; ++i)
	{
		int elem;
		cin >> elem;
		cout << count[elem].first << " " << count[elem].second << "\n";
	}
}