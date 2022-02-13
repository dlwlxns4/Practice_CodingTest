#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> ar;
vector<int> result;

void DFS()
{
	if (result.size() == M)
	{
		for (auto i : result)
		{
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < ar.size(); ++i)
	{
		result.push_back(ar[i]);
		DFS();
		result.pop_back();
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		ar.push_back(i + 1);
	}

	DFS();
}