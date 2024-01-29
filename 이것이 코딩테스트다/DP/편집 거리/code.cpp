#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;


int dp[5001][5001];
int main() {


    string a, b;
    cin >> a;
    cin >> b;

    //초기값 수정
    for(int x =0; x<=a.size(); x++)
    {
        for(int y = 0; y<=b.size(); y++)
        {
            if(x == 0 && y == 0) dp[x][y] = 0;
            else if(x == 0) dp[x][y] = y;
            else if(y == 0) dp[x][y] = x;
        }
    }

    for(int x = 1; x<=a.size(); x++)
    {
        for(int y = 1; y <=b.size(); y++)
        {
            if(a[x] == b[y]) dp[x][y] = dp[x-1][y-1];
            else
            {
                dp[x][y] = 1 + min(dp[x][y-1], min(dp[x-1][y-1], dp[x-1][y]));
            }
        }
    }

    cout << dp[a.size()][b.size()];
    return 0;
}
