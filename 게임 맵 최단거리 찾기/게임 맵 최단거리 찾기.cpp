#include<vector>
#include <queue>


using namespace std;

struct Point {
    int row, col, dist;
};
int D[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };


int bfs(int startRow, int startCol, vector<vector<int>> maps) {
    const int N = maps.size(), M = maps[0].size();


    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<Point> myqueue;
    visited[startRow][startCol] = true;
    myqueue.push({ startRow,startCol,1 });

    while (!myqueue.empty()) {
        Point curr = myqueue.front();
        myqueue.pop();
        if (curr.row == N - 1 && curr.col == M - 1)
            return curr.dist;


        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N - 1 || nc<0 || nc>M - 1) continue; // 맵 범위 넘어갔을 때
            if (visited[nr][nc]) continue; //방문한 곳일 때 
            if (maps[nr][nc] == 0) continue; //벽일 때

            visited[nr][nc] = true;
            myqueue.push({ nr,nc,curr.dist + 1 });
        }

    }
    return -1;

}


int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int startRow = 0, startCol = 0;


    answer = bfs(startRow, startCol, maps);
    return answer;
}