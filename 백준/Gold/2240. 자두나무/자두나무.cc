
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

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;
int T, W;
int DP[1001][31];
int Tree[1001];
int max_count = 0;

void Input()
{
    cin >> T >> W;
    for (int i = 1; i <= T; i++)
    {
        cin >> Tree[i];
    }
}

void Init()
{
}

void Slove()
{
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= i && j <= W; j++)
        {
            if (j == 0)
            {   
                if(Tree[i] == 1) DP[i][j] = DP[i - 1][j] + 1;
                max_count = max(max_count, DP[i][j]);
                continue;
            }

            if (Tree[i] == 1 && j % 2 == 0)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + 1;
            else if (Tree[i] == 2 && j % 2 == 1)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]);

            max_count = max(max_count, DP[i][j]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();

    cout << max_count << endl;
}
