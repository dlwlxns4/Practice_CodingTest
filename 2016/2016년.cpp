#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> month = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    vector<string> day = { "SUN", "MON", "TUE", "WED", "THU", "FRI" ,"SAT" };
    int totalday = 0;

    for (int i = 0; i < a - 1; i++) {
        totalday += month[i];
    }totalday += b;

    answer = day[((totalday + 4) % 7)];


    return answer;
}