#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> ar;
vector<bool> isVisted;
vector<int> result;

void Combination(int depth, int index, vector<int> com)
{
	if (depth == M)
	{
		for (auto i : com)
		{
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	if (index >= ar.size())
	{
		return;
	}

	com[depth] = ar[index];
	Combination(depth + 1, index + 1, com);
	Combination(depth, index + 1, com);
}

int main() {


	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		ar.push_back(i + 1);
	}

	vector<int> com(M);
	Combination(0, 0, com);
}