#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

int solution(int n) {
    bitset<32> currentNumBit(n);
    int nextNum = n + 1;

    while (currentNumBit.count() != bitset<32>(nextNum).count()) {
        nextNum++;
    }

    int answer = nextNum;
    return answer;
}