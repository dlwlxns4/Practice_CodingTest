#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> Map;
vector<vector<int>> Dist;

int EatCount = 0;
int SharkSize = 2;
pair<int, int> SharkPos; 

struct Target
{
    int y, x, dist;
    bool found;
};

void Input();
void Solution();
Target BFS();

void Input()
{
    cin >> N;
    Map.resize(N, vector<int>(N));
    Dist.resize(N, vector<int>(N, -1));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 9)
            {
                SharkPos = make_pair(j, i); 
                Map[i][j] = 0;              
            }
        }
    }
}

Target BFS()
{
    static const int dx[4] = { 0, 0, -1, 1 };
    static const int dy[4] = { -1, 1, 0, 0 };

    for (int y = 0; y < N; ++y) fill(Dist[y].begin(), Dist[y].end(), -1);

    queue<pair<int, int>> q;
    int sx = SharkPos.first;
    int sy = SharkPos.second;

    Dist[sy][sx] = 0;
    q.push({ sx, sy }); // (x, y)

    int bestDist = -1, bestX = -1, bestY = -1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (newX < 0 || newX >= N || newY < 0 || newY >= N) 
                continue; 

            if (Dist[newY][newX] != -1 || Map[newY][newX] > SharkSize)
                continue;

            Dist[newY][newX] = Dist[y][x] + 1;

            if (Map[newY][newX] > 0 && Map[newY][newX] < SharkSize)
            {
                if (bestDist == -1 || bestDist > Dist[newY][newX] || (Dist[newY][newX] == bestDist && (newY < bestY || (newY == bestY && newX < bestX))))
                {
                    bestDist = Dist[newY][newX];
                    bestX = newX;
                    bestY = newY;
                }
            }

            q.push({ newX, newY });
        }
    }

    if (bestDist == -1)
        return { -1,-1,-1, false };

    return { bestY, bestX, bestDist, true };
}


void Solution()
{
    int count = 0;

    while (true)
    {
        Target target = BFS();

        if (target.found == false)
            break;

        SharkPos = make_pair(target.x, target.y);
        Map[target.y][target.x] = 0;

        count += target.dist;
        EatCount++;
        if(EatCount == SharkSize) 
		{
			EatCount = 0;
			SharkSize++;
		}
    }

    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solution();
}
