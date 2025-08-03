#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int N;
int maxDp[3], minDp[3];

void Input();
void Solution();

void Input()
{
	cin >> N;
}

void Solution()
{
	int a, b, c;
	cin >> a >> b >> c;

	maxDp[0] = a;
	maxDp[1] = b;
	maxDp[2] = c;

	minDp[0] = a;
	minDp[1] = b;
	minDp[2] = c;

	for (int i = 1; i < N; ++i)
	{
		int tmpMax[3], tmpMin[3];
		cin >> a >> b >> c;

		tmpMax[0] = max(maxDp[0], maxDp[1]) + a;
		tmpMax[1] = max({ maxDp[0], maxDp[1], maxDp[2] }) + b;
		tmpMax[2] = max(maxDp[1], maxDp[2]) + c;
		
		tmpMin[0] = min(minDp[0], minDp[1]) + a;
		tmpMin[1] = min({ minDp[0], minDp[1], minDp[2] }) + b;
		tmpMin[2] = min(minDp[1], minDp[2]) + c;

		maxDp[0] = tmpMax[0];
		maxDp[1] = tmpMax[1];
		maxDp[2] = tmpMax[2];

		minDp[0] = tmpMin[0];
		minDp[1] = tmpMin[1];
		minDp[2] = tmpMin[2];
	}

	int maxResult = max({ maxDp[0], maxDp[1], maxDp[2] });
	int minResult = min({ minDp[0], minDp[1], minDp[2] });

	cout << maxResult << " " << minResult << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	Solution();
}