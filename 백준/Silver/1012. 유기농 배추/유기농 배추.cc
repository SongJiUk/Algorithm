
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
bool isVisit[51][51];
int MAPS[51][51];
int T, M, N, K;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
priority_queue<pair<int, pair<int, int>>> pq;

void Init();
void Slove();

void Input()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;

        Init();

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            MAPS[x][y] = 1;
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (MAPS[i][j] == 1)
                {
                    pq.push({0, {i, j}});
                }
            }
        }

        Slove();
    }
}

void Init()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            MAPS[i][j] = 0;
            isVisit[i][j] = false;
        }
    }
}

void Slove()
{
    int count = 0;
    while (!pq.empty())
    {
        int priority_num = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (isVisit[x][y])
            continue;

        if (priority_num == 0 && !isVisit[x][y])
        {
            count++;
        }

        isVisit[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && MAPS[nx][ny] == 1)
            {
                pq.push({priority_num + 1, {nx, ny}});
            }
        }
    }

    cout << count << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    // Init();
    // Slove();
}
