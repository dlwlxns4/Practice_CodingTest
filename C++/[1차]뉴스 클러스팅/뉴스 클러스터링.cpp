#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string str1, string str2) {
    int answer = 65536;
    vector<string> stringVec1, stringVec2;
    int interNum = 0, sumNum = 0;

    transform(str1.cbegin(), str1.cend(), str1.begin(), ::tolower);
    transform(str2.cbegin(), str2.cend(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
            stringVec1.push_back(str1.substr(i, 2));
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
            stringVec2.push_back(str2.substr(i, 2));
    }

    for (int i = 0; i < stringVec1.size(); i++) {
        for (int j = 0; j < stringVec2.size(); j++) {
            if (stringVec1[i] == stringVec2[j]) {
                interNum++;
                stringVec2.erase(stringVec2.begin() + j);
                j--;
                break;
            }

        }
    }
    sumNum += stringVec1.size() + stringVec2.size();

    if (sumNum == 0)
        return 65536;
    else
        answer = 65536 * interNum / sumNum;

    return answer;
}