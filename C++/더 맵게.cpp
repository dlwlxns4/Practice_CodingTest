#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto scv : scoville)  //1. PQ �ʱ�ȭ 
		pq.push(scv);

	while (pq.top() < K) {// pq�� ��Ʈ�� K���� �������� ����
		if (pq.size() <= 1) return -1; // 1������������ ���� �� �����Ƿ� ���ǹ� ó��
		int newScovile = pq.top(); // ��Ʈ�� �� �������� pop�ϱ�
		pq.pop();
		pq.push(newScovile + pq.top() * 2); // ���� ���� ����ֱ�
		pq.pop(); // �������Ƿ� ������ ��Ʈ�� �����ϱ�
		answer++;
	}

	return answer;
}