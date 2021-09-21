#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    string tmp(name.size(), 'A');
    int index = 0;

    while (tmp != name) {

        //answer 횟수 추가하기
        name[index] - 'A' > 'Z' + 1 - name[index] ? answer += 'Z' + 1 - name[index] : answer += name[index] - 'A';


        //바꿔주고 그 해당 인덱스에 값 변경해주기 
        tmp[index] = name[index];

        cout << tmp << endl;
        if (tmp == name) break;



        //오른쪽으로 가야할지 왼쪽으로 가야할지가 가장 문제인 문제이다.
        for (int move = 0; move < name.size(); move++) {
            //오른쪽으로 갈 때 
            if (tmp[(move + index) % name.size()] != name[(move + index) % name.size()]) {
                index = (move + index) % name.size();
                answer += move;
                break;
            }
            //왼쪽으로 갈 때 
            else if (tmp[(index + name.size() - move) % name.size()] != name[(index + name.size() - move) % name.size()]) {
                index = (index + name.size() - move) % name.size();
                answer += move;
                break;
            }
        }
    }

    return answer;
}