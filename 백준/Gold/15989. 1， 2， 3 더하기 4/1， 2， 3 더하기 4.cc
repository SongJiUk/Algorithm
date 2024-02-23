#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 1e9

using namespace std;

int DP[10001][4];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    vector<int> testcase;
    vector<int> count_vec;
    
    for(int i =0; i<T; i++)
    {
        int x;
        cin >> x;
        testcase.push_back(x);
    }

    DP[0][0] = 0;
    DP[1][1] = 1;
    DP[2][1] = DP[2][2] =1;
    DP[3][1] = DP[3][2] = DP[3][3] = 1;

    for(int i =4; i<10001; i++)
    {
        DP[i][1] = DP[i-1][1];
        DP[i][2] = DP[i-2][1] + DP[i-2][2];
        DP[i][3] = DP[i-3][1] + DP[i-3][2] + DP[i-3][3]; 
    }

    for(int i =0; i<testcase.size(); i++)
    {
        int num = testcase[i];
        cout << DP[num][1] + DP[num][2] + DP[num][3] << endl;
    }
}