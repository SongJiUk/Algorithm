#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;



int map[501][501];
int dp[501][501];
int main(void) {

    int n;
    cin >>n;
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<i+1; j++)
        {
            int x;
            cin >> x;
            dp[i][j] = x;
        }
    }


    for(int i =1; i<n; i++)
    {
        for(int j =0; j<i+1; j++)
        {
            if((j-1) < 0 ) dp[i][j] += dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j] + dp[i][j], dp[i-1][j-1] + dp[i][j]);
        }
    }

int result =0;
    for(int i =0; i<n; i++)
    {
        result = max(result, dp[n-1][i]);
    }

    cout << result;
}