#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <string>

#define endl '\n'
#define MAX 1e9
using namespace std;

int min_count = MAX;
void DFS(long long _a, int _target, int _count)
{
    if(_a == _target)
    {
        min_count = min(min_count, _count);
        return;
    }
    else if(_a > _target) return;
    else
    {
        DFS(_a *2, _target, _count + 1);

        _a = _a*10 +1;

        DFS(_a, _target, _count + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A;
    int B;
    cin >> A >> B;

    DFS(A, B, 1);

    if(min_count == MAX) cout << -1 << endl;
    else cout << min_count << endl;
}   
