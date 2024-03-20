#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;
int DP[1001][1001];
/*
 이항계수는 N, K가 주어지고 (N/K) 일때 nCK =   N! / (N-K)! * K! 이다. 재귀 사용하면 될듯
 */
int N, K;
void Input()
{
    cin >> N >> K;
}

void Init()
{   

    for(int i =0; i<=N; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            if(i==0 || j == i) DP[i][j] = 1;
            else DP[i][j] = DP[i-1][j-1] % 10007 + DP[i-1][j] % 10007;
        }
    }
}

void Slove()
{
    cout << DP[N][K] % 10007 << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
