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

vector<vector<int>> DP(100001, vector<int>(2));

void Init();

void Input()
{
    Init();

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        cout << DP[N][1] << " " << DP[N][0] << endl;
    }
}

void Init()
{
    DP[1][0] = 0, DP[1][1] = 1, DP[2][0] = 1, DP[2][1] = 1, DP[3][0] = 2, DP[3][1] = 2;

    for (int i = 4; i < 100001; i++)
    {
        DP[i][0] = ((DP[i - 3][1] + DP[i - 2][1]) % 1000000009 + DP[i - 1][1]) % 1000000009;
        DP[i][1] = ((DP[i - 3][0] + DP[i - 2][0]) % 1000000009 + DP[i - 1][0]) % 1000000009;
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
    // Init();
    // Slove();
}
