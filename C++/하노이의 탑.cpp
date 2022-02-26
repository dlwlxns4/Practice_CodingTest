#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;


void Hanoi(int num, int from, int by, int to)
{

    if (num == 1)
    {
        vector<int> tmp;
        tmp.push_back(from);
        tmp.push_back(to);
        answer.push_back(tmp);
    }
    else
    {
        Hanoi(num - 1, from, to, by);

        vector<int> tmp;
        tmp.push_back(from);
        tmp.push_back(to);
        answer.push_back(tmp);

        Hanoi(num - 1, by, from, to);


    }
}

vector<vector<int>> solution(int n) {

    Hanoi(n, 1, 2, 3);

    return answer;
}