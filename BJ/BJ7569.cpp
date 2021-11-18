//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int N, M, H;
//
//struct Pos
//{
//	int h;
//	int r;
//	int c;
//};
//
//
////��ȯ�� ������ ���� ����
////�Ű����� : ��ġ
////������ ã�� ��
//void bfs(queue<Pos>& q, vector<vector<vector<int>>>& map, vector<vector<vector<bool>>>& isVisited)
//{
//
//	int dr[] = { -1,1,0,0 };
//	int dc[] = { 0,0,-1,1 };
//	int dh[] = { -1,1 };
//
//	while (!q.empty())
//	{
//		int r = q.front().r;
//		int c = q.front().c;
//		int h = q.front().h;
//
//		isVisited[h][r][c] = true;
//		q.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int nr = dr[i] + r;
//			int nc = dc[i] + c;
//			
//
//			//�ش���ġ�� ��ȿ���� �Ǵ�
//			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
//				continue;
//
//			//�湮�� ������ �Ǵ�
//			if (isVisited[h][nr][nc])
//				continue;
//
//			//1���� �Ǵ�
//			if (map[h][nr][nc] != 0)
//				continue;
//
//			map[h][nr][nc] = map[h][r][c] + 1;
//
//			q.push({h, nr, nc });
//		}
//
//		for (int i = 0; i < 2; ++i)
//		{
//			int nh = dh[i] + h;
//			if (nh < 0 || nh >= H)
//				continue;
//
//			if (isVisited[nh][r][c])
//				continue;
//
//			if (map[nh][r][c] != 0)
//				continue;
//
//			map[nh][r][c] = map[h][r][c] + 1;
//
//			q.push({ nh, r, c });
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
//	queue<Pos> q;
//
//	cin >> M;
//	cin >> N;
//	cin >> H;
//
//	vector<vector<vector<int>>> map(H, vector<vector<int>>(N, vector<int>(M)));
//	vector<vector<vector<bool>>> isVisited(H, vector<vector<bool>>(N, vector<bool>(M)));
//
//	for (int h = 0; h < H; ++h)
//	{
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < M; ++j)
//			{
//				cin >> map[h][i][j];
//				if (map[h][i][j] == 1)
//					q.push({ h,i,j });
//			}
//		}
//	}
//
//
//	bfs(q, map, isVisited);
//
//
//	int max = 0;
//
//	for (int h = 0; h < H; ++h)
//	{
//		for (int i = 0; i < N; ++i)
//		{
//			if (count(map[h][i].begin(), map[h][i].end(), 0))
//			{
//				cout << -1;
//				return 0;
//			}
//
//			max = (*max_element(map[h][i].begin(), map[h][i].end())) > max ? (*max_element(map[h][i].begin(), map[h][i].end())) : max;
//		}
//	}
//
//	cout << max - 1;
//
//}