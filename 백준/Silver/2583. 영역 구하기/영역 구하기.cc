
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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int M, N, K, counts;
int MAPS[101][101];
bool isVisit[101][101];
vector<int> vec;
priority_queue<pair<int, pair<int, int>>> pq;
void Init();
void Slove();




void Input()
{
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int ld_x, ld_y, ru_x, ru_y;
        cin >> ld_y >> ld_x >> ru_y >> ru_x;

        for (int x = ld_x + 1; x <= ru_x; x++)
        {
            for (int y = ld_y + 1; y <= ru_y; y++)
            {
                MAPS[x][y] = -1;
            }
        }
    }
}

void Init()
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (MAPS[i][j] == 0)
            {
                pq.push({0, {i, j}});
            }
        }
    }
}

void Slove()
{
    counts = 0;
    while (!pq.empty())
    {
        int priority = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (isVisit[x][y])
            continue;

        if (priority == 0)
            counts++;

        MAPS[x][y] = counts;
        isVisit[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= M && ny > 0 && ny <= N && MAPS[nx][ny] == 0 && !isVisit[nx][ny])
            {
                pq.push({1, {nx, ny}});
            }
        }
    }

    for (int i = 1; i <= counts; i++)
    {
        int num = 0;
        for(int x = 1; x <= M; x++)
        {
            for(int y = 1; y<=N; y++)
            {
                if(MAPS[x][y] == i)
                {
                    num++;
                }
            }
        }
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    cout << counts << endl;
    for(int i =0; i<vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
