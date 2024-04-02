
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

vector<int> DP(100001);
int N;

void Input()
{
    cin >> N;
}

void Init()
{
    for(int i = 1; i <=N; i++)
    {
        DP[i] = i;
    }
}

void Slove()
{
    for(int i =4; i<= N; i++)
    {
        for(int j = 2; j * j <= i; j++)
        {
            DP[i] = min(DP[i], DP[i - j*j] + 1);
        }
    }


    cout << DP[N] << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Input();
    Init();
    Slove();
}
