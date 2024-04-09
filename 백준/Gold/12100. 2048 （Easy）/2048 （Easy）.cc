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
int N;

vector<vector<int>> MAPS(21, vector<int>(21));
int max_num = 0;

int CheckHighScore(vector<vector<int>> _MAPS)
{

    int num = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            num = max(num, _MAPS[i][j]);
        }
    }

    return num;
}

void DFS(int _count)
{

    if (_count == 5)
    {
        return;
    }

    // 순서대로 상,하 ,좌,우
    int NewMAPS[21][21];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            NewMAPS[i][j] = MAPS[i][j];
        }
    }

    // 상,하, 좌, 우
    for (int i = 0; i < 4; i++)
    {       
        queue<int> q;
        switch (i)
        {
        case 0:

            for (int j = 0; j < N; j++)
            {
                for (int i = 0; i < N; i++)
                {
                    if (MAPS[i][j] != 0)
                        q.push(MAPS[i][j]);
                    MAPS[i][j] = 0;
                }

                int index = 0;
                while (!q.empty())
                {
                    int num = q.front();
                    q.pop();

                    if (MAPS[index][j] == 0)
                    {
                        MAPS[index][j] = num;
                    }
                    else if (MAPS[index][j] == num)
                    {
                        MAPS[index][j] *= 2;
                        index++;
                    }
                    else
                    {
                        index++;
                        MAPS[index][j] = num;
                    }
                }
            }
            break;
        case 1:
            if(_count == 0)
            {
                
            }
            for (int j = 0; j < N; j++)
            {
                for (int i = N - 1; i >= 0; i--)
                {
                    if (MAPS[i][j] != 0)
                        q.push(MAPS[i][j]);
                    MAPS[i][j] = 0;
                }

                int index = N - 1;
                while (!q.empty())
                {
                    int num = q.front();
                    q.pop();

                    if (MAPS[index][j] == 0)
                    {
                        MAPS[index][j] = num;
                    }
                    else if (MAPS[index][j] == num)
                    {
                        MAPS[index][j] *= 2;
                        index--;
                    }
                    else
                    {
                        index--;
                        MAPS[index][j] = num;
                    }
                }
            }

            break;

        case 2:
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (MAPS[i][j] != 0)
                        q.push(MAPS[i][j]);
                    MAPS[i][j] = 0;
                }

                int index = 0;
                while (!q.empty())
                {
                    int num = q.front();
                    q.pop();

                    if (MAPS[i][index] == 0)
                    {
                        MAPS[i][index] = num;
                    }
                    else if (MAPS[i][index] == num)
                    {
                        MAPS[i][index] *= 2;
                        index++;
                    }
                    else
                    {
                        index++;
                        MAPS[i][index] = num;
                    }
                }
            }

            break;

        case 3:
            for (int i = 0; i < N; i++)
            {
                for (int j = N - 1; j >= 0; j--)
                {
                    if (MAPS[i][j] != 0)
                        q.push(MAPS[i][j]);
                    MAPS[i][j] = 0;
                }

                int index = N - 1;
                while (!q.empty())
                {
                    int num = q.front();
                    q.pop();

                    if (MAPS[i][index] == 0)
                    {
                        MAPS[i][index] = num;
                    }
                    else if (MAPS[i][index] == num)
                    {
                        MAPS[i][index] *= 2;
                        index--;
                    }
                    else
                    {
                        index--;
                        MAPS[i][index] = num;
                    }
                }
            }
            break;
        }

        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (max_num < MAPS[x][y])
                    max_num = MAPS[x][y];
            }
        }   

        DFS(_count + 1);

        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                MAPS[x][y] = NewMAPS[x][y];
            }
        }
    }
}

void Input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAPS[i][j];
        }
    }
}

void Init()
{
}

void Slove()
{
    DFS(0);
    cout << max_num << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
