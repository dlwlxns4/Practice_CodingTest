#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();


    //�迭 ����
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());


    //������ �Ȱ������� �������� �ִ� ����
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                answer++;
                lost.erase(lost.begin() + i);
                i--;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }

    //�� ������
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j] + 1) {
                answer++;
                reserve.erase(reserve.begin() + j);
                break;
            }
            else if (lost[i] == reserve[j] - 1) {
                answer++;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }

    return answer;
}