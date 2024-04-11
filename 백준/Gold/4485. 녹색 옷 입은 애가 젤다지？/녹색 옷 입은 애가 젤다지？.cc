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
int T, N;
int MAPS[126][126];
int ANSWER[126][126];

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

void Input()
{
    int num = 0;
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> MAPS[i][j];
                ANSWER[i][j] = MAX;
            }
        }

        num++;
        pq.push({MAPS[0][0], {0, 0}});
        ANSWER[0][0] = MAPS[0][0];

        while (!pq.empty())
        {
            int money = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                {
                    if(ANSWER[nx][ny] > money + MAPS[nx][ny])
                    {
                        ANSWER[nx][ny] = money + MAPS[nx][ny];
                        pq.push({ANSWER[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        cout << "Problem " << num << ": " << ANSWER[N - 1][N - 1] << endl;
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
    // Init();
    // Slove();
}
