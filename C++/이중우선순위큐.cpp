#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;

    int elemCount = 0;

    for (int i = 0; i < operations.size(); ++i)
    {
        istringstream ss(operations[i]);
        string stringBuffer;
        vector<string> x;

        while (getline(ss, stringBuffer, ' '))
        {
            x.push_back(stringBuffer);

        }
        if (x[0] == "I")
        {
            elemCount++;
            maxPQ.push(stoi(x[1]));
            minPQ.push(stoi(x[1]));
        }
        else if (x[0] == "D")
        {

            if (stoi(x[1]) == 1)
            {
                if (maxPQ.empty() == false)
                {
                    maxPQ.pop();
                    elemCount--;

                }

            }
            else
            {
                if (minPQ.empty() == false)
                {
                    minPQ.pop();
                    elemCount--;
                }
            }

            if (elemCount == 0)
            {
                while (maxPQ.empty() == false)
                {
                    maxPQ.pop();
                }
                while (minPQ.empty() == false)
                {
                    minPQ.pop();
                }
            }
        }
    }

    if (maxPQ.empty() == true)
        answer.push_back(0);
    else
        answer.push_back(maxPQ.top());

    if (minPQ.empty() == true)
        answer.push_back(0);
    else
        answer.push_back(minPQ.top());



    return answer;
}