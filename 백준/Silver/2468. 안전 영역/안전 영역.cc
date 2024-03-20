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

int maps[100][100];
bool isVisit[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int max_count = 1;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int max_num = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> maps[i][j];
            max_num = max(max_num, maps[i][j]);
        }
    }

    queue<pair<int, int>> q;
    int rain = 0;
    while (rain <= max_num)
    {
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (maps[i][j] > rain)
                {
                    if (isVisit[i][j])
                        continue;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if (isVisit[x][y])
                            continue;
                        isVisit[x][y] = true;

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];

                            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                                continue;
                            if (isVisit[nx][ny])
                                continue;
                            if (maps[nx][ny] > rain)
                                q.push({nx, ny});
                        }
                    }

                    count++;
                }
            }
        }
        rain++;
        for(int i = 0; i<N; i++)
        {
            for(int j =0; j<N; j++)
            {
                isVisit[i][j] = false;
            }
        }

        max_count = max(max_count, count);
    }

    cout << max_count << endl;
}
