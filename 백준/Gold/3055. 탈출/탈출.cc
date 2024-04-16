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

int R, C;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<char>> MAPS(51, vector<char>(51));
vector<vector<bool>> isVisit(51, vector<bool>(51));
queue<pair<int, pair<int, int>>> q;
pair<int, int> goal_pos;
void Input()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            MAPS[i][j] = s[j];
            if (MAPS[i][j] == 'D')
                goal_pos = {i, j};
        }
    }
}

void Init()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (MAPS[i][j] == '*')
            {
                isVisit[i][j] = true;
                q.push({0, {i, j}});
            }
                
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (MAPS[i][j] == 'S')
            {
                isVisit[i][j] = true;
                q.push({0, {i, j}});
            }
                
        }
    }
}

void Slove()
{
    bool flag = false;
    while (!q.empty())
    {
        int count = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(MAPS[x][y] == 'S' && x == goal_pos.first && y == goal_pos.second)
        {
            cout << count << endl;
            flag = true;
            break;
        }

        char c = MAPS[x][y];

        for(int i =0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || ny <0 || nx >= R || ny >= C) continue;
            if(isVisit[nx][ny]) continue;

            if(c == 'S')
            {
                if(MAPS[nx][ny] == '.' || MAPS[nx][ny] == 'D')
                {
                    MAPS[nx][ny] = 'S';
                    isVisit[nx][ny] = true;
                    q.push({count+1, {nx, ny}});
                }
            }
            else
            {
                if(MAPS[nx][ny] == '.')
                {
                    MAPS[nx][ny] = '*';
                    isVisit[nx][ny] = true;
                    q.push({count +1, {nx,ny}});
                }
            }
            
            

        }
    }

    if(!flag) cout << "KAKTUS" << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
