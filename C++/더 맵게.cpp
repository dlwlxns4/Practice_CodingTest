#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto scv : scoville)  //1. PQ 초기화 
		pq.push(scv);

	while (pq.top() < K) {// pq의 루트가 K보다 작을때만 진행
		if (pq.size() <= 1) return -1; // 1개만있을때는 섞을 수 없으므로 조건문 처리
		int newScovile = pq.top(); // 루트의 값 가져오고 pop하기
		pq.pop();
		pq.push(newScovile + pq.top() * 2); // 섞은 값을 집어넣기
		pq.pop(); // 섞었으므로 기존의 루트는 제거하기
		answer++;
	}

	return answer;
}