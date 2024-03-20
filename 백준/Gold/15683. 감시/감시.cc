#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int maps[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
vector<pair<int, int>> vec;
int min_count = MAX;

void checkMap(int _x, int _y, int _dir)
{
    _dir %= 4;

    while (true)
    {
        int nx = _x + dx[_dir];
        int ny = _y + dy[_dir];
        _x = nx;
        _y = ny;
        if (nx <= 0 || ny <= 0 || nx > N || ny > M) return;
        if(maps[nx][ny] == 6) return;
        if(maps[nx][ny] != 0) continue;
        maps[nx][ny] = -1;
    }
}

void DFS(int _index)
{
    if (_index == vec.size())
    {
        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (maps[i][j] == 0)
                    count++;
            }
        }
        min_count = min(min_count, count);
        return;
    }

    int x = vec[_index].first;
    int y = vec[_index].second;

    int temp[9][9];

    
    for (int dir = 0; dir < 4; dir++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                temp[i][j] = maps[i][j];
            }
        }

        if (maps[x][y] == 1)
        {
            // 상우하좌
            checkMap(x, y, dir);
        }
        else if (maps[x][y] == 2)
        {
            // 상하, 좌우
            checkMap(x, y, dir);
            checkMap(x, y, dir + 2);
        }
        else if (maps[x][y] == 3)
        {
            checkMap(x, y, dir);
            checkMap(x, y, dir + 1);
        }
        else if (maps[x][y] == 4)
        {
            checkMap(x, y, dir);
            checkMap(x, y, dir + 1);
            checkMap(x, y, dir + 2);
        }
        else if (maps[x][y] == 5)
        {
            checkMap(x, y, dir);
            checkMap(x, y, dir + 1);
            checkMap(x, y, dir + 2);
            checkMap(x, y, dir + 3);
        }


        DFS(_index+1);

        for(int i =1; i<=N; i++)
        {
            for(int j =1; j<=M; j++)
            {
                maps[i][j] = temp[i][j];
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] != 0 && maps[i][j] != 6)
                vec.push_back({i, j});
        }
    }

    DFS(0);

    cout << min_count << endl;
}
