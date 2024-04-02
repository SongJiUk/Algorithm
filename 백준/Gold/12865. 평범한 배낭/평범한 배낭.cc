
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

int N, K, W, V;
vector<pair<int, int>> vec(101);
vector<vector<int>> DP(101, vector<int>(100001));
void Input()
{
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> W >> V;
        vec[i] = {W, V};
    }
}

void Init()
{
}

void Slove()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (vec[i].first <= j)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - vec[i].first] + vec[i].second);
            else
                DP[i][j] = DP[i-1][j];
        }
    }

    cout << DP[N][K] << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
