#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    string tmp(name.size(), 'A');
    int index = 0;

    while (tmp != name) {

        //answer Ƚ�� �߰��ϱ�
        name[index] - 'A' > 'Z' + 1 - name[index] ? answer += 'Z' + 1 - name[index] : answer += name[index] - 'A';


        //�ٲ��ְ� �� �ش� �ε����� �� �������ֱ� 
        tmp[index] = name[index];

        cout << tmp << endl;
        if (tmp == name) break;



        //���������� �������� �������� ���������� ���� ������ �����̴�.
        for (int move = 0; move < name.size(); move++) {
            //���������� �� �� 
            if (tmp[(move + index) % name.size()] != name[(move + index) % name.size()]) {
                index = (move + index) % name.size();
                answer += move;
                break;
            }
            //�������� �� �� 
            else if (tmp[(index + name.size() - move) % name.size()] != name[(index + name.size() - move) % name.size()]) {
                index = (index + name.size() - move) % name.size();
                answer += move;
                break;
            }
        }
    }

    return answer;
}