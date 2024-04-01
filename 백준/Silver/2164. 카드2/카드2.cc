
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

int N;
queue<int> q;
void Input()
{
    cin >> N;
}

void Init()
{
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
}

void Slove()
{
    while (q.size() != 1)
    {
        q.pop();
        int num = q.front();
        q.pop();
        q.push(num);
    }

    cout << q.front() << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
