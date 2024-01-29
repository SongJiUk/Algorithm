#include <iostream>
#include <queue>

using namespace std;


int map[21][21];
int dp[21][21];

int main(void) {

    int T, n, m;
    cin >> T;
    cin >> n >> m;
    for(int t = 0; t <T; t++)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                int a;
                cin >> a;
                map[i][j] = a;
            }
        }


        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                dp[i][j] = map[i][j];
            }
        }

        for(int j = 1; j<m; j++)
        {
            for(int i = 0; i<n; i++)
            {
                //왼쪽위
                int leftup;
                if(i==0) leftup = 0;
                else
                {
                    leftup = dp[i-1][j-1];
                }
                //왼쪽
                int left;
                left = dp[i][j-1];
                //왼쪽 아래
                int leftdown;
                if(i==n-1) leftdown = 0;
                else
                {
                    leftdown = dp[i+1][j-1];
                }

                dp[i][j] = dp[i][j] + max(leftup, max(left, leftdown));
            }
        }

            int result = 0;
            for(int i =0; i <n; i++)
            {
                result = max(result, dp[i][m-1]);
            }

            cout << result << endl;
    }

}
