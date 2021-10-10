#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int totalWeight = 0; // �ٸ��� ���� �� �߷� 
	queue<int> queue; // �ٸ��� �ö�� �ִ� ����
	vector<int> time; // �ٸ��� �ö�� �ִ� ���� ������ �Ÿ�

	while (truck_weights.size() != 0 || !queue.empty())
	{

		for (int i = 0; i < time.size(); i++) // �ٸ��� �ִ� ���� �ö� �Ÿ��� ������Ų��
		{
			time[i]++;
		}
		if (time.size() != 0 && time[0] == bridge_length) // ���� �ٸ��� �ǳ��� ��
		{
			time.erase(time.begin());  // �� ���� �ش��ϴ� �Ÿ� ������ �����
			totalWeight -= queue.front(); // ���� �ѷ��� ���ְ�
			queue.pop(); // �� ������ ���ش�.
		}

		if (truck_weights.size() != 0 && totalWeight + truck_weights[0] <= weight)
		{ // �ٸ��� �ö��ִ� ���� ���� ���� �ö� �� �ִ��� �˻��Ѵ�.
			totalWeight += truck_weights[0]; // �� ���Ը� ������Ų��.
			time.push_back(0); // ������ ���� ������ �����Ѵ�.
			queue.push(truck_weights[0]); // �� ���� �ش��ϴ� ���������� �����Ѵ�.
			truck_weights.erase(truck_weights.begin()); // ���� ������ �����.
		}

		answer++;
	}



	return answer;
}