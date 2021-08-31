#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    int answer = 0;
    int pre1 = 2;
    int ppre2 = 1;
    long long sum = 2;
    for (int i = 3; i < n; i++) {
        sum = ((pre1 % 1234567) + (ppre2 % 1234567)) % 1234567;
        ppre2 = pre1;
        pre1 = sum;
    }
    return answer = sum;
}