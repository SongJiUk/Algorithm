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

int T, n;
void Input()
{
    cin >> T;

    for(int i =0; i<T; i++)
    {
        int n;
        cin >> n;
        vector<vector<int>> vec(3, vector<int>(n+1, 0));
        vector<vector<int>> DP(3, vector<int>(n+1, 0));

        for(int i =1; i<=2; i++)
        {
            for(int j =1; j<=n; j++)
            {
                cin >> vec[i][j];
            }
        }

        DP[1][1] = vec[1][1];
        DP[2][1] = vec[2][1];

        for(int i = 2; i<=n; i++)
        {
            DP[1][i] = max(DP[2][i-1] + vec[1][i], DP[2][i-2] + vec[1][i]);
            DP[2][i] = max(DP[1][i-1] + vec[2][i], DP[1][i-2] + vec[2][i]);
        }

        int max_num = max(DP[1][n], DP[2][n]);

        cout << max_num << endl;
    }
}

void Init()
{
}



void Slove()
{
   
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
