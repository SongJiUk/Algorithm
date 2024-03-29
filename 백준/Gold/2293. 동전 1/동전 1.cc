
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

typedef long long ll;
#define endl '\n'
#define MAX 1e9
using namespace std;

int N, K;
ll DP[10001];
vector<int> coins;
void Input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }
}

void Init()
{
    DP[0] = 1;
}

void Slove()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = coins[i]; j <= K; j++)
        {
            DP[j] = DP[j] + DP[j - coins[i]];
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

    cout << DP[K] << endl;
}
