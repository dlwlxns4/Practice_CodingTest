#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int N;
int ans = 0;

void DFS(int sum, int elem)
{
	if (sum == elem)
	{
		ans++;
		return;
	}

	if (sum > elem)
	{
		return;
	}

	DFS(sum + 1, elem);
	DFS(sum + 2, elem);
	DFS(sum + 3, elem);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int elem;
		cin >> elem;
		DFS(1, elem);
		DFS(2, elem);
		DFS(3, elem);
		cout << ans << "\n";
		ans = 0;
	}

}