//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//
//using namespace std;
//
//int T;
//int N, M, K;
//
//
////��ȯ�� ������ ���� ����
////�Ű����� : ��ġ
////������ ã�� ��
//int dfs(int r, int c, vector<vector<int>>& map, vector<vector<bool>>& isVisited)
//{
//	isVisited[r][c] = true;
//
//	int result = 1;
//
//	int dr[] = { -1,1,0,0 };
//	int dc[] = { 0,0,-1,1 };
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int nr = dr[i] + r;
//		int nc = dc[i] + c;
//
//		//�ش���ġ�� ��ȿ���� �Ǵ�
//		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
//			continue;
//
//		//�湮�� ������ �Ǵ�
//		if (isVisited[nr][nc])
//			continue;
//
//		//1���� �Ǵ�
//		if (map[nr][nc] != 1)
//			continue;
//
//		result += dfs(nr, nc, map, isVisited);
//	}
//
//	return result;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> T;
//
//	for (int t = 0; t < T; ++t)
//	{
//		int result = 0;
//		cin >> N;
//		cin >> M;
//		cin >> K;
//
//		vector<vector<int>> map(N, vector<int>(M));
//		vector<vector<bool>> isVisited(N, vector<bool>(M));
//
//		for (int i = 0; i < K; ++i)
//		{
//			int r, c;
//			cin >> r;
//			cin >> c;
//
//			map[r][c] = 1;
//		}
//
//
//		//������ ���� ��ȸ
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < M; ++j)
//			{
//				//�湮���� ���� ������ ���ƾ� ��
//				if (isVisited[i][j] == false && map[i][j] == 1)
//				{
//					if (dfs(i, j, map, isVisited))
//						result++;
//				}
//			}
//		}
//		cout << result << endl;
//	}
//
//}