#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> dp(land);
    int firstMax, secondMax;
    int firstPosition, secondPosition;

    for (int i = 1; i < dp.size(); i++) {
        firstMax = *max_element(land[i - 1].begin(), land[i - 1].end());
        firstPosition = max_element(land[i - 1].begin(), land[i - 1].end()) - land[i - 1].begin();
        land[i - 1].erase(land[i - 1].begin() + firstPosition);
        secondMax = *max_element(land[i - 1].begin(), land[i - 1].end());
        secondPosition = max_element(land[i - 1].begin(), land[i - 1].end()) - land[i - 1].begin();


        for (int j = 0; j < dp[i].size(); j++) {
            if (j != firstPosition) {
                dp[i][j] += firstMax;
                land[i][j] += firstMax;
            }

        }dp[i][firstPosition] += secondMax;
        land[i][firstPosition] += secondMax;
    }


    answer = *max_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());





    return answer;
}