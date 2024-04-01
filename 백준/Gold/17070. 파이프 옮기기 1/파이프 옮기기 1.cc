
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

typedef long long ll;
#define endl '\n'
#define MAX 1e9
using namespace std;

// 가로, 대각, 세로
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
int MAPS[17][17];
int N;
queue<pair<int, pair<int, int>>> q;
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> MAPS[i][j];
        }
    }
}

void Init()
{
    q.push({0, {1, 2}});
}

void Slove()
{
    int counts = 0;
    while (!q.empty())
    {
        int dir = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (x == N && y == N)
        {
            counts++;
            continue;
        }

        switch (dir)
        {
        case 0:
            // 0, 1
            for (int i = 0; i < 2; i++)
            {
                int nx = 0;
                int ny = 0;

                if (i == 1)
                {
                    bool isImpossible = false;
                    for (int j = 0; j < 3; j++)
                    {
                        nx = x + dx[j];
                        ny = y + dy[j];

                        if (nx <= 0 || nx > N || ny <= 0 || ny > N || MAPS[nx][ny] == 1)
                        {
                            isImpossible = true;
                            break;
                        }
                    }

                    if (!isImpossible)
                    {
                        nx = x + dx[i];
                        ny = y + dy[i];
                        q.push({i, {nx, ny}});
                    }
                }
                else
                {
                    nx = x + dx[i];
                    ny = y + dy[i];

                    if (nx > 0 && nx <= N && ny > 0 && ny <= N && MAPS[nx][ny] == 0)
                    {
                        q.push({i, {nx, ny}});
                    }
                }
            }
            break;

        case 1:
            // 0,1,2(대각선은 모두 체크해줘야함.)
            for (int i = 0; i < 3; i++)
            {
                int nx = 0;
                int ny = 0;
                if (i == 1)
                {
                    bool isImpossible = false;
                    for (int j = 0; j < 3; j++)
                    {
                        nx = x + dx[j];
                        ny = y + dy[j];

                        if (nx <= 0 || nx > N || ny <= 0 || ny > N || MAPS[nx][ny] == 1)
                        {
                            isImpossible = true;
                            break;
                        }
                    }

                    if (!isImpossible)
                    {
                        nx = x + dx[i];
                        ny = y + dy[i];
                        q.push({i, {nx, ny}});
                    }
                }
                else
                {

                    nx = x + dx[i];
                    ny = y + dy[i];

                    if (nx > 0 && nx <= N && ny > 0 && ny <= N && MAPS[nx][ny] == 0)
                    {
                        q.push({i, {nx, ny}});
                    }
                }
            }
            break;

        case 2:
            // 1,2
            for (int i = 1; i < 3; i++)
            {
                int nx = 0;
                int ny = 0;
                if (i == 1)
                {
                    bool isImpossible = false;
                    for (int j = 0; j < 3; j++)
                    {
                        nx = x + dx[j];
                        ny = y + dy[j];

                        if (nx <= 0 || nx > N || ny <= 0 || ny > N || MAPS[nx][ny] == 1)
                        {
                            isImpossible = true;
                            break;
                        }
                    }

                    if (!isImpossible)
                    {
                        nx = x + dx[i];
                        ny = y + dy[i];
                        q.push({i, {nx, ny}});
                    }
                }
                else
                {
                    nx = x + dx[i];
                    ny = y + dy[i];

                    if (nx > 0 && nx <= N && ny > 0 && ny <= N && MAPS[nx][ny] == 0)
                    {
                        q.push({i, {nx, ny}});
                    }
                }
            }
            break;
        }
    }

    cout << counts << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
