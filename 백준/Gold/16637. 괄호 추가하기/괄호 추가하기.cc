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
string s;
int max_sum = -MAX;
int SUM(char _oper, int _a, int _b)
{
    if (_oper == '+')
        return _a += _b;
    if (_oper == '-')
        return _a -= _b;
    if (_oper == '*')
        return _a *= _b;
}

void DFS(int _index, int _sum)
{

    if (_index >= N)
    {
        max_sum = max(max_sum, _sum);
        return;
    }

    char oper = _index == 0 ? '+' : s[_index - 1];
    if (_index + 2 < N)
    {
        int sum = SUM(s[_index + 1], s[_index] - '0', s[_index + 2] - '0');
        DFS(_index + 4, SUM(oper, _sum, sum));
    }

    DFS(_index + 2, SUM(oper, _sum, s[_index] - '0'));
}

void Input()
{
    cin >> N;
    cin >> s;
}

void Init()
{
}

void Slove()
{
    DFS(0, 0);
    cout << max_sum << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
