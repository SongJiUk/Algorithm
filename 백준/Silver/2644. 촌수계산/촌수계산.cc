#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N, M, p1, p2;
vector<pair<int, int>> vec;
queue<pair<int, int>> q;
bool isVisit[100];
void DFS()
{
}

void Input()
{
    cin >> N;
    cin >> p1 >> p2;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int parent, child;
        cin >> parent >> child;
        vec.push_back({parent, child});
    }
}

void Init()
{
    q.push({p1, 0});
}

void Slove()
{
    bool isFind = false;
    while (!q.empty())
    {
        int target = q.front().first;
        int count = q.front().second;
        isVisit[target] = true;

        if (target == p2)
        {
            cout << count << endl;
            isFind = true;
            break;
        }

        q.pop();
        for (int i = 0; i < M; i++)
        {
            if (vec[i].first == target && !isVisit[vec[i].second])
            {
                q.push({vec[i].second, count + 1});
                isVisit[vec[i].second] = true;
            }

            if (vec[i].second == target && !isVisit[vec[i].first])
            {
                q.push({vec[i].first, count + 1});
                isVisit[vec[i].first] = true;
            }
        }
    }

    if(!isFind) cout << -1 << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
