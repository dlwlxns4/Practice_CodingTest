//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define INF 987654321
//
//using namespace std;
//
//
//// 1. distance / distnace [i] : ���� ���� -> i�ΰ��� �ִ� ���. distance[start] = 0 / INF;
//// 2. �߰ߵǾ���, �湮���� ���� ���� �� �ִ� ����� ������ ã�´�. 
//// 3. �ش� ����(v)�� �����ؼ� ���� ��, �ִ� ��ΰ� �ִ��� Ž���Ѵ�. distance [i] = min(distance[i], distance[v] + graph[v][i]);
//// 4. ��� ������ ���ؼ� �ִ� ��θ� ã�� ������ 2������ �ݺ��Ѵ�.
////start : ���� ����
//
//
//
//
//int N, M, startNode;
//
//std::vector<int> GetShortestPath2(const vector<vector<pair<int, int>>>& map)
//{
//	// distance �迭 �����
//	// �߰ߵ��� ���� ������ ��� INF��.
//	vector<int> dist(N, INF);
//	// ���� ������ �Ÿ��� 0�̴�.
//	dist[startNode - 1] = 0;
//
//	// �켱���� ť�� �̿��Ѵ�.
//	priority_queue<pair<int, int>> pq;
//
//	// ���� ������ �־��ش�.
//	pq.emplace(0, startNode - 1);
//
//	// dist�� ��� ���� ã�� ������
//	while (false == pq.empty())
//	{
//		// dist �߿��� ���� �ּҰ��� ������ ������ �̾Ƴ���.
//		int w = -pq.top().first;
//		int v = pq.top().second;
//		pq.pop();
//
//		// �ش� ������ �̿����� ��, �ִ� �Ÿ��� ã�� �� �ִ��� üũ�Ѵ�.
//		//for (int node = 0; node < N; ++node)
//		//{
//		//	if (dist[node] > dist[v] + graph[v][node])
//		//	{
//		//		dist[node] = dist[v] + graph[v][node];
//
//		//		pq.emplace(-dist[node], node);
//		//	}
//		//}
//
//		//��������Ʈ
//		for (pair<int, int> i : map[v])
//		{
//			if (dist[i.first] > dist[v] + i.second)
//			{
//				dist[i.first] = dist[v] + i.second;
//
//				pq.emplace(-dist[i.first], i.first);
//			}
//		}
//
//	}
//
//	return dist;
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N;
//	cin >> M;
//	cin >> startNode;
//
//	vector<vector<pair<int, int>>> map2(N);
//	for (int i = 0; i < M; ++i)
//	{
//		int start = 0, end = 0, weight = 0;
//		cin >> start;
//		cin >> end;
//		cin >> weight;
//
//		map2[start - 1].push_back({ end - 1, weight });
//	}
//
//
//	auto path = GetShortestPath2(map2);
//	for (int i : path)
//	{
//		if (i == INF)
//			cout << "INF" << endl;
//		else
//			cout << i << endl;
//	}
//}
//
