
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
char MAPS[51][51];
// bool isVisit[51][51];
vector<vector<int>> isVisit(51, vector<int>(51));
bool isStart[51][51];
int R, C;
queue<pair<int, int>> que;
queue<pair<int, int>> q;
int max_count = 0;
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
            if (MAPS[i][j] == 'L')
                q.push({i, j});
        }
    }
}

void Init()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
        }
    }
}

int Find(int x, int y, vector<vector<int>> _isvisit)
{
    int cnt = 0;
    _isvisit[x][y] = 1;
    que.push({x, y});
    while (!que.empty())
    {

        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !_isvisit[nx][ny] && MAPS[nx][ny] == 'L')
            {
                que.push({nx, ny});
                _isvisit[nx][ny] = _isvisit[x][y] + 1;
                cnt = max(cnt, _isvisit[nx][ny]);
            }
        }
    }
    return cnt;
}

void Slove()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        max_count = max(max_count, Find(x, y, isVisit));
    }

    cout << max_count -1 << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
