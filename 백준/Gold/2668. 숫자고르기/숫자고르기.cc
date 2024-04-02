
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
int A[101];
int B[101];
bool isVisit[101];
set<int> s;
int counts = 0;

void DFS(int _start, int _next)
{


    if(_start == _next)
    {
        counts++;
        s.insert(_start);
        return;
    }

    if(isVisit[_next]) return;

    isVisit[_next] = true;
    DFS(_start, B[_next]);

}

void Input()
{
    cin >> N;
    for(int i =1; i<=N; i++)
    {
        A[i] = i;
        cin >> B[i];
    }
}

void Init()
{
}

void Slove()
{
    for(int i =1; i<=N; i++)
    {
        DFS(i, B[i]);
        memset(isVisit, false, 101);
    }
    
    cout << counts << endl;
    for(auto a : s)
    {
        cout << a << endl;
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
