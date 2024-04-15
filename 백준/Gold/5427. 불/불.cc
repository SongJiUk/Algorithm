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
int T, h, w;

void Input()
{
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> h >> w;
        vector<vector<char>> MAPS(w, vector<char>(h));
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> isVisit(w, vector<bool>(h));
        for (int i = 0; i < w; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < h; j++)
            {
                MAPS[i][j] = s[j];
                isVisit[i][j] = false;
                if (MAPS[i][j] == '*')
                {
                    q.push({0, {i, j}});
                    isVisit[i][j] = true;
                }
            }
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                if (MAPS[i][j] == '@')
                {
                    q.push({1, {i, j}});
                    isVisit[i][j] = true;
                }
            }
        }

        bool flag = false;
        while (!q.empty())
        {
            int count = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            char c = MAPS[x][y];

            if (c == '@')
            {

                if (x <= 0 || x >= w - 1 || y <= 0 || y >= h - 1)
                {
                    cout << count << endl;
                    flag = true;
                    break;
                }

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= w || ny >= h)
                        continue;

                    if (isVisit[nx][ny])
                        continue;

                    if (MAPS[nx][ny] == '#' || MAPS[nx][ny] == '*')
                        continue;

                    MAPS[nx][ny] = '@';
                    q.push({count + 1, {nx, ny}});
                    isVisit[nx][ny] = true;
                }
            }
            else if (c == '*')
            {
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= w || ny >= h)
                        continue;
                        
                    if (isVisit[nx][ny])
                        continue;

                    if (MAPS[nx][ny] == '#' || MAPS[nx][ny] == '*')
                        continue;

                    MAPS[nx][ny] = '*';
                    q.push({count + 1, {nx, ny}});
                    isVisit[nx][ny] = true;
                }
            }
        }

        if (!flag)
            cout << "IMPOSSIBLE" << endl;
    }
}

void Init()
{
}

void Slove()
{
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
