#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

void ErastoTenes(int N, int M, vector<int>& ar)
{
	for (int i = 2; i <= M; ++i)
	{
		if (ar[i] == 0)
		{
			continue;
		}

		for (int j = 2 * i; j <= M; j += i)
		{
			ar[j] = 0;
		}
	}

	for (int i = N; i <= M; ++i)
	{
		if (ar[i] != 0)
		{
			cout << ar[i] << "\n";
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> ar(M + 1);
	for (int i = 2; i <= M; ++i)
	{
		ar[i] = i;
	}
	ErastoTenes(N, M, ar);


}