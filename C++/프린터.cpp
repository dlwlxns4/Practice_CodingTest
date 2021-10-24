#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> queue;
	priority_queue<int> pq;

	for (int i = 0; i < priorities.size(); i++) {
		queue.push(make_pair(priorities[i], i));
		pq.push(priorities[i]);
	}

	while (!queue.empty()) {
		if (queue.front().first == pq.top()) {
			if (queue.front().second == location) {
				return answer + 1;
			}
			else {
				answer++;
				queue.pop();
				pq.pop();
			}
		}
		else {
			queue.push(queue.front());
			queue.pop();
		}
	}

	return answer;
}