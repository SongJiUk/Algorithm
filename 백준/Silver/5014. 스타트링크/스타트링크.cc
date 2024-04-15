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

int F, S, G, U, D;

queue<pair<int, int>> q;


void Input()
{
    cin >> F >> S >> G >> U >> D;
}

void Init(vector<bool>& _isVisit)
{
    q.push({S, 0});
    _isVisit[S] = true;
}

void Slove(vector<bool>& _isVisit)
{
    // F층 건물에서 , S층에서, G층까지 위로 U칸씩, 아래로 D칸씩가는 엘베
    // 큐로 해야될듯
    bool flag = false;
    while (!q.empty())
    {
        int floor = q.front().first;
        int count = q.front().second;
        q.pop();

        if (floor == G)
        {
            cout << count << endl;
            flag = true;
            break;
        }
        if (floor + U <= F && !_isVisit[floor + U])
        {
            _isVisit[floor + U] = true;
            q.push({floor + U, count + 1});
        }

        if (floor - D > 0 && !_isVisit[floor - D])
        {
            _isVisit[floor - D] = true;
            q.push({floor - D, count + 1});
        }
    }

    if (!flag)
        cout << "use the stairs" << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    vector<bool> isVisit(F+1);
    Init(isVisit);
    Slove(isVisit);
}
