#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int areaSize;

void DFS(vector<vector<bool>>& isVisited, vector<vector<int>> picture, int m, int n, int posX, int posY)
{
    static int dx[4] = { 0,0,1,-1 };
    static int dy[4] = { 1,-1,0,0 };



    for (int i = 0; i < 4; ++i)
    {
        if (posX + dx[i] >= 0 && posX + dx[i] < m)
        {
            if (posY + dy[i] >= 0 && posY + dy[i] < n)
            {
                if (isVisited[posY + dy[i]][posX + dx[i]] == false && picture[posY + dy[i]][posX + dx[i]] == picture[posY][posX])
                {
                    isVisited[posY + dy[i]][posX + dx[i]] = true;
                    DFS(isVisited, picture, m, n, posX + dx[i], posY + dy[i]);
                    areaSize++;
                }
            }
        }
    }


}



vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<bool>> isVisited(m, vector<bool>(n, false));


    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (picture[j][i] != 0 && isVisited[j][i] == false)
            {
                areaSize = 0;
                DFS(isVisited, picture, m, n, i, j);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, areaSize);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}