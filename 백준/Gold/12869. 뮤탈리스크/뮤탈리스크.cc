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

int N;
int DP[61][61][61];
vector<int> vec(3);
vector<vector<int>> v =
    {
        {1, 3, 9},
        {1, 9, 3},
        {3, 1, 9},
        {3, 9, 1},
        {9, 1, 3},
        {9, 3, 1}};

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
}

void Init()
{
    memset(DP, -1, sizeof(DP));
}

int Find(int _scv1, int _scv2, int _scv3)
{
    if (_scv1 == 0 && _scv2 == 0 && _scv3 == 0)
        return 0;

    else if (_scv1 < 0)
        return Find(0, _scv2, _scv3);
    else if (_scv2 < 0)
        return Find(_scv1, 0, _scv3);
    else if (_scv3 < 0)
        return Find(_scv1, _scv2, 0);

    int& dp = DP[_scv1][_scv2][_scv3];
    if(dp != -1) return dp;
    dp = MAX;

    for(int i =0; i<6; i++)
    {
        dp = min(dp, Find(_scv1 - v[i][0], _scv2 - v[i][1], _scv3 - v[i][2]) + 1);
    }

    return dp;
}
void Slove()
{
    cout << Find(vec[0], vec[1], vec[2]) << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
