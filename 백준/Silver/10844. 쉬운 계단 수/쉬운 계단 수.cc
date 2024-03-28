
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

int N;
ll DP[101][10];
void Input()
{
    cin >> N;
}

void Init()
{
    for (int i = 1; i <= 9; i++)
    {
        DP[1][i] = 1;
    }
}

void Slove()
{
    for (int i = 2; i <= N; i++)
    {
        DP[i][0] = DP[i - 1][1] % 1000000000;

        for(int j = 1; j<=8; j++)
        {
            DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000;
        }

        DP[i][9] = DP[i - 1][8] % 1000000000;
    }

    ll sum = 0;
    for(int i=0; i<=9; i++)
    {
        sum += DP[N][i];
    }

    cout << sum % 1000000000<< endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
