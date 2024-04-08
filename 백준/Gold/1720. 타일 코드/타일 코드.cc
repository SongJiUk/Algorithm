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
int DP[31];
int N;

void Input()
{
    cin >> N;
}

void Init()
{
    DP[0] =1;
    DP[1] =1;
    for (int i = 2; i <= 30; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2] * 2;
    }
}

void Slove()
{
    if (N % 2 == 0)
    {
        cout << (DP[N] + DP[N/2] + DP[N / 2 -1] * 2) / 2 << endl;
    }
    else
    {
        cout << (DP[N] + DP[(N - 1) / 2]) / 2 << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
