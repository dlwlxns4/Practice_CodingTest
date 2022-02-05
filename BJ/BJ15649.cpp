#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> ar;
vector<bool> isVisted;
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
		if (isVisted[i] == false)
		{
			isVisted[i] = true;
			result.push_back(ar[i]);
			DFS();
			result.pop_back();
			isVisted[i] = false;
		}
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		ar.push_back(i + 1);
		isVisted.push_back(false);
	}

	DFS();
}