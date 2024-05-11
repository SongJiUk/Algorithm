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
pair<char, char> node[26];

void PreOrder(char _c)
{
    if(_c == '.') return;
    cout << _c;
    PreOrder(node[_c - 'A'].first);
    PreOrder(node[_c - 'A'].second);
}

void InOrder(char _c)
{
    if(_c == '.') return;
    InOrder(node[_c - 'A'].first);
    cout << _c;
    InOrder(node[_c - 'A'].second);
}

void PostOrder(char _c)
{
    if(_c == '.') return;
    PostOrder(node[_c - 'A'].first);
    PostOrder(node[_c - 'A'].second);
    cout << _c;
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char p, l, r;
        cin >> p >> l >> r;

        node[p - 'A'].first = l;
        node[p - 'A'].second = r;
    }
}

void Init()
{
}

void Slove()
{
    PreOrder('A');
    cout << endl;
    InOrder('A');
    cout << endl;
    PostOrder('A');
    cout << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
