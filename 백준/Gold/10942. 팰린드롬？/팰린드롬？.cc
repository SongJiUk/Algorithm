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
int DP[2001][2001];

int N, M, S, E;
vector<int> vec(2001);
void Init();
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> vec[i];
    }
    Init();
    cin >> M;
    for(int i =0; i< M; i++)
    {
        int x,y;
        cin >> x >> y;

        cout << DP[x][y] << endl;
    }
}

void Init()
{
    for (int i = 1; i <= N; i++)
    {
        DP[i][i] = 1;

        if (i != N)
            if (vec[i] == vec[i + 1])
                DP[i][i + 1] = 1;
    }
    int sum = 0;
    for (int num = 2; num < N; num++)
    {
        for (int i = 1; i <= N - num; i++)
        {
            sum = i + num;
            if (vec[i] == vec[sum] && DP[i + 1][sum-1])
            {
                DP[i][sum] = 1;
            }
        }
    }
}

void Slove()
{
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    //Init();
    //Slove();
}
