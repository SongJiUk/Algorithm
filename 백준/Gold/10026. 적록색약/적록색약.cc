
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
char MAPS[101][101];
char MAPS_UnNormal[101][101];
bool isVisit[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> pq;

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            if (s[j] == 'R')
                MAPS_UnNormal[i][j] = 'G';
            else
                MAPS_UnNormal[i][j] = s[j];

            MAPS[i][j] = s[j];
        }
    }
}

void Init()
{
    pq.push({0, {0, 0}});
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            isVisit[i][j] = false;
        }
    }
}

void Slove()
{
    int counts = 0;
    while (!pq.empty())
    {
        int priority_num = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        char color = MAPS[x][y];
        pq.pop();

        if (priority_num == 0 && !isVisit[x][y])
            counts++;

        isVisit[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisit[nx][ny])
            {
                if (MAPS[nx][ny] == color)
                {
                    pq.push({priority_num + 1, {nx, ny}});
                }
                else
                {
                    pq.push({0, {nx, ny}});
                }
            }
        }
    }
    cout << counts << " ";
    Init();
    counts = 0;
    while (!pq.empty())
    {
        // R == G
        int priority_num = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        char color = MAPS_UnNormal[x][y];
        pq.pop();

        if (priority_num == 0 && !isVisit[x][y])
            counts++;

        isVisit[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisit[nx][ny])
            {
                if (MAPS_UnNormal[nx][ny] == color)
                {
                    pq.push({priority_num + 1, {nx, ny}});
                }
                else
                {
                    pq.push({0, {nx, ny}});
                }
            }
        }
    }
    cout << counts <<  endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
