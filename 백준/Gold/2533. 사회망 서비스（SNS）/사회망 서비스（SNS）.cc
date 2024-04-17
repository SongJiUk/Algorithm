
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

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N;
int DP[1000001][2];
bool isVisit[1000001];
vector<int> Tree[1000001];

void Input()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
}

void Init()
{
}


void DFS(int _x)
{
    isVisit[_x] = true;
    //0 - 자신이 얼리어답터, 1 - 자신이 얼리어답터가 아님.
    DP[_x][0] = 1;

    for (int i = 0; i < Tree[_x].size(); i++)
    {
        int child = Tree[_x][i];
        if (isVisit[child]) continue;
        DFS(child);
        //부모가 얼리어답터가 아니면. 자식은 얼리어답터여야 한다.
        DP[_x][1] += DP[child][0];

        //부모가 얼리어답터라면, 자식이 얼리어답터이거나, 아니어도 된다.
        DP[_x][0] += min(DP[child][0], DP[child][1]);
    }

}

void Slove()
{
    DFS(1);

    cout << min(DP[1][0], DP[1][1]) << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init(); 
    Slove();

}
