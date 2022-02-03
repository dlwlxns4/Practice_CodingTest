#include <iostream>

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int prime[1001];


int N, M;
vector<string> comb;
vector<char> ar;


void Combination(int index, int depth, string str)
{
	if (depth == N)
	{
		int count = 0;
		int consonantCount = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			{
				count++;
			}
			else
			{
				consonantCount++;
			}
		}
		if (count != 0 && consonantCount >= 2)
		{
			cout << str << "\n";
		}
		return;
	}

	if (index >= ar.size())
	{
		return;
	}

	str[depth] = ar[index];
	Combination(index + 1, depth + 1, str);
	Combination(index + 1, depth, str);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		char elem;
		cin >> elem;
		ar.push_back(elem);
	}

	sort(ar.begin(), ar.end());

	string str(N, ' ');
	Combination(0, 0, str);

	//for (auto i : comb)
	//{
	//	cout << i << "\n";
	//}
}
