#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int maps[6][6];
int DP[6][6];
int dx[3] = {1, 1, 1};
int dy[3] = {-1, 0, 1};
int N = 0, M = 0;
int min_num = MAX;
void DFS(int _a, int _b, int _dir)
{

    if (_a == N-1)
    {
        min_num = min(min_num, DP[_a][_b]);
        return;
    }

    for(int i =0; i<3; i++)
    {
        if(_dir == i) continue;

        int nx = _a + dx[i];
        int ny = _b + dy[i];
        if(nx >= N || ny < 0 || ny >= M) continue;

        DP[nx][ny] = DP[_a][_b] + maps[nx][ny];
        DFS(nx, ny, i);
    }

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> maps[i][j];
            if(i == 0) DP[0][j] = maps[i][j];
        }
    }

    for(int i = 0; i<M; i++)
    {
        DFS(0, i, -1);
    }

    cout << min_num << endl;
}
