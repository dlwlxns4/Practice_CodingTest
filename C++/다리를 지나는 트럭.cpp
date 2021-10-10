#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int totalWeight = 0; // 다리에 오른 총 중량 
	queue<int> queue; // 다리에 올라와 있는 차량
	vector<int> time; // 다리에 올라와 있는 차가 지나간 거리

	while (truck_weights.size() != 0 || !queue.empty())
	{

		for (int i = 0; i < time.size(); i++) // 다리에 있는 차가 올라간 거리를 증가시킨다
		{
			time[i]++;
		}
		if (time.size() != 0 && time[0] == bridge_length) // 차가 다리를 건넜을 때
		{
			time.erase(time.begin());  // 그 차에 해당하는 거리 정보를 지운다
			totalWeight -= queue.front(); // 무게 총량을 없애고
			queue.pop(); // 차 정보를 없앤다.
		}

		if (truck_weights.size() != 0 && totalWeight + truck_weights[0] <= weight)
		{ // 다리에 올라가있는 차와 다음 차가 올라갈 수 있는지 검사한다.
			totalWeight += truck_weights[0]; // 차 무게를 증가시킨다.
			time.push_back(0); // 지나간 길이 정보를 저장한다.
			queue.push(truck_weights[0]); // 그 차에 해당하는 무게정보를 저장한다.
			truck_weights.erase(truck_weights.begin()); // 벡터 정보를 지운다.
		}

		answer++;
	}



	return answer;
}