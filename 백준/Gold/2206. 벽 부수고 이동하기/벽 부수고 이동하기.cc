#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <limits.h>
#include <cmath>
#include <list>

typedef long long ll;
#define endl '\n'
#define MAX 1e9
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;
char MAPS[1001][1001];
int isVisit[1001][1001][2];

queue<pair<int, pair<int, int>>> q;

void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            MAPS[i][j] = s[j - 1];
        }
    }
}

void Init()
{
    q.push({0, {1, 1}});
    isVisit[1][1][0] = 1;
}

int Slove()
{
    while (!q.empty())
    {

        int BreakWall = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        if (x == N && y == M)
        {
            return isVisit[x][y][BreakWall];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= N && ny > 0 && ny <= M)
            {
                if (MAPS[nx][ny] == '0' && isVisit[nx][ny][BreakWall] == 0)
                {
                    isVisit[nx][ny][BreakWall] = isVisit[x][y][BreakWall] + 1;
                    q.push({BreakWall, {nx, ny}});
                }
                else if (MAPS[nx][ny] == '1' && BreakWall == 0 && isVisit[nx][ny][1] == 0)
                {
                    isVisit[nx][ny][1] = isVisit[x][y][BreakWall] + 1;
                    q.push({1, {nx, ny}});
                }
            }
        }
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    cout << Slove() << endl;
}
