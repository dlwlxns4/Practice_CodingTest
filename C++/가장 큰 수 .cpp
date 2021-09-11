#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    return  ab > ba;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);
    if (numbers[0] == 0)
        return answer = "0";

    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }


    return answer;
}