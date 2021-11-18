//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
////���� ���;
//bool graph[1001][1001];
//
//// 
//vector<int> graph2[1001];
//
//int N, M, V;
//
//
//// ������Ŀ����� dfs
////node : ���� ����
//void dfs(int node)
//{
//	//visited ���
//	static bool isVisited[1001] = { false };
//
//	stack<int> stk;
//	stk.push(node);
//
//	while (stk.empty() == false)
//	{
//		// ���ÿ��� ������ �湮�� ������ �����´�.
//		int vertex = stk.top();
//		stk.pop();
//
//		if (isVisited[vertex])
//			continue;
//
//		cout << vertex << " ";
//		//�湮�� ������ ǥ���Ѵ�.
//		isVisited[vertex] = true;
//
//		//���ߵ� ��带 ��� �湮�Ѵ�.
//		for (int i = N; i >= 1; --i)
//		{
//			//�湮���� �ʾҰ�, ������ ����� ģ������ �湮
//			if (isVisited[i] == false && graph[vertex][i] == true)
//			{
//				// �湮�� ��带 ���ÿ� �߰��Ѵ�.
//				stk.push(i);
//			}
//		}
//
//	}
//}
//
//// ��������Ʈ������ dfs
//// node : ���� ����
//void dfs2(int node)
//{
//	//1. �湮�� ������ ǥ���� �ڷᱸ��
//	static bool isVisited[1001] = { false };
//
//	//2. ���� ����
//	stack<int> stk;
//	stk.push(node);
//
//	//3. ��� ���� �湮�� ������ ��ȸ
//	while (!stk.empty())
//	{
//		//4. ���ÿ��� ������ �湮�� ������ �����´�.
//		int vertex = stk.top();
//		stk.pop();
//
//		//5. �̹� �湮�� ����� �ǳʶڴ�.
//		if (isVisited[vertex])
//			continue;
//
//		cout << vertex << " ";
//
//		//6. ������ �湮�Ѵ�.
//		isVisited[vertex] = true;
//
//		//7. ����� ���� �� �湮���� ���� ������ ���ÿ� �߰��Ѵ�.
//		for (int e : graph2[vertex])
//		{
//			if (isVisited[e] == false)
//			{
//				stk.push(e);
//			}
//		}
//	}
//}
//
//// ��ͷ� ������ dfs / ���� ��� ���
//void dfsR(int node)
//{
//	// 1. �湮�� ������ ǥ���� Set�� ����
//	static bool isVisited[1001] = { false };
//
//
//	isVisited[node] = true;
//	cout << node << " ";
//
//	for (int i = 1; i <= N; ++i)
//	{
//		if (isVisited[i] == false && graph[node][i] == true)
//			dfsR(i);
//	}
//}
//
//// ��ͷ� ������ dfs / ���� ��� ���
//void dfs2R(int node)
//{
//	// 1. �湮�� ������ ǥ���� Set�� ����
//	static bool isVisited[1001] = { false };
//
//
//	isVisited[node] = true;
//	cout << node << " ";
//
//	for (int e : graph2[node])
//	{
//		if (isVisited[e]== false)
//			dfs2R(e);
//	}
//}
//
//
//void bfs(int node)
//{
//	static bool isVisited[1001] = { false };
//	queue<int> q;
//
//	q.push(node);
//
//	while (!q.empty())
//	{
//		int vertex = q.front();
//		q.pop();
//
//		if (isVisited[vertex])
//			continue;
//
//		isVisited[vertex] = true;
//
//		cout << vertex << " ";
//
//		for (int i = 1; i <= N; ++i)
//		{
//			//�湮���� �ʾҰ�, ������ ����� ģ������ �湮
//			if (isVisited[i] == false && graph[vertex][i] == true)
//			{
//				// �湮�� ��带 ���ÿ� �߰��Ѵ�.
//				q.push(i);
//			}
//		}
//
//	}
//}
//
////void dpss(int node)
////{
////	static bool isVisited[1001] = { false };
////
////	isVisited[node] = false;
////	cout << node << " ";
////
////	for (int e : graph2[node])
////	{
////		if (isVisited[e] == false)
////		{
////			dpss(e);
////		}
////	}
////}
//
//void bfs2(int node)
//{
//	static bool isVisited[1001] = { false };
//	queue<int> q;
//
//	q.push(node);
//
//	while (!q.empty())
//	{
//		int vertex = q.front();
//		q.pop();
//
//		if (isVisited[vertex])
//			continue;
//
//		isVisited[vertex] = true;
//
//		cout << vertex << " ";
//
//		for (int e: graph2[vertex])
//		{
//			//�湮���� �ʾҰ�, ������ ����� ģ������ �湮
//			if (isVisited[e] == false)
//			{
//				// �湮�� ��带 ���ÿ� �߰��Ѵ�.
//				q.push(e);
//			}
//		}
//
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//
//	cin >> N;
//	cin >> M;
//	cin >> V;
//	for (int i = 0; i < M; ++i)
//	{
//		int s, e;
//		cin >> s;
//		cin >> e;
//
//		graph[s][e] = graph[e][s] = true;
//
//		graph2[s].push_back(e);
//		graph2[e].push_back(s);
//	}
//
//	//dfs
//	dfs(V);
//	cout << endl;
//	dfs2(V);
//	cout << endl;
//	dfsR(V);
//	cout << endl;
//	dfs2R(V);
//	cout << endl;
//
//	//bfs
//	bfs(V);
//	cout << endl;
//	bfs2(V);
//}