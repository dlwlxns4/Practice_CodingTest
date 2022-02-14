#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int N;
	cin >> N;
	vector<int> ar(N + 1);

	ar[1] = 1;
	ar[2] = 2;
	for (int i = 3; i <= N; ++i)
	{
		ar[i] = ar[i - 1] + ar[i - 2];
		ar[i] %= 10007;
	}

	cout << ar[N];
}