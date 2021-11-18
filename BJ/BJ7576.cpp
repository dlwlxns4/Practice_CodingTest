//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int N, M;
//
//
//
////��ȯ�� ������ ���� ����
////�Ű����� : ��ġ
////������ ã�� ��
//void bfs(queue<pair<int, int>>& q, vector<vector<int>>& map, vector<vector<bool>>& isVisited)
//{
//
//	int dr[] = { -1,1,0,0 };
//	int dc[] = { 0,0,-1,1 };
//
//
//	while (!q.empty())
//	{
//		int r = q.front().first;
//		int c = q.front().second;
//
//		isVisited[r][c] = true;
//		q.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int nr = dr[i] + r;
//			int nc = dc[i] + c;
//
//			//�ش���ġ�� ��ȿ���� �Ǵ�
//			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
//				continue;
//
//			//�湮�� ������ �Ǵ�
//			if (isVisited[nr][nc])
//				continue;
//
//			//1���� �Ǵ�
//			if (map[nr][nc] != 0)
//				continue;
//
//			map[nr][nc] = map[r][c] + 1;
//
//			q.push({ nr, nc });
//		}
//	}
//
//}
//
//int main()
//{
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	queue<pair<int, int>> q;
//
//	cin >> M;
//	cin >> N;
//
//	vector<vector<int>> map(N, vector<int>(M));
//	vector<vector<bool>> isVisited(N, vector<bool>(M));
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			cin >> map[i][j];
//			if (map[i][j] == 1)
//				q.push({ i,j });
//		}
//	}
//
//
//
//	bfs(q, map, isVisited);
//
//
//	int max = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		if (count(map[i].begin(), map[i].end(), 0))
//		{
//			cout << -1;
//			return 0;
//		}
//		max = (*max_element(map[i].begin(), map[i].end())) > max ? (*max_element(map[i].begin(), map[i].end())) : max;
//
//	}
//	cout << max - 1;
//
//}