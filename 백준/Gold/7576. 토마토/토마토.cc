
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

typedef long long ll;
#define endl '\n'
#define MAX 1e9
using namespace std;

int N, M;
int MAP[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, pair<int, int>>> q;
void Input()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            
            if (MAP[i][j] == 1)
            {
                q.push({0, {i, j}});
            }
        }
    }
}

void Init()
{
}

void Slove()
{
    int max_count = 0;
    bool isNotAllRipen = false;
    while (!q.empty())
    {
        int count = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;

        max_count = max(max_count, count);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && MAP[nx][ny] == 0)
            {
                MAP[nx][ny] = 1;
                q.push({count + 1, {nx, ny}});
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] == 0)
            {
                isNotAllRipen = true;
                break;
            }
        }
        if (isNotAllRipen)
            break;
    }

    if (isNotAllRipen)
        cout << -1 << endl;
    else
        cout << max_count << endl;
    ;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
