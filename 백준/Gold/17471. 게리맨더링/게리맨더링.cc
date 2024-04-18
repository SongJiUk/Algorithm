
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
vector<int> Town_Population(11);
bool isVisit[11];
bool isConnect[11][11];
bool isSelect[11];
int min_sum = MAX;
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Town_Population[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int a;
            cin >> a;
            isConnect[i][a] = true;
            isConnect[a][i] = true;
        }
    }
}

void Init()
{

}

bool Connect_Check(vector<int>& _vec, bool _isSelect)
{
    for (int i = 1; i <= N; i++)
    {
        isVisit[i] = false;
    }
    queue<int> q;
    q.push(_vec[0]);
    isVisit[_vec[0]] = true;
    int count = 1;

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            /* 
            BFS 탐색 조건 3개
            조건 1 : 현재 구역과 탐색하려는 구역이 연결되어 있는지 ?               
            조건 2 : 탐색하려는 구역이 선거구에 맞는 놈인지 ?               
            조건 3 : 아직 방문하지 않은 구역인지 ?
            */
            if (isConnect[num][i] && isSelect[i] == _isSelect && !isVisit[i])
            {
                count++;
                isVisit[i] = true;
                q.push(i);
            }
        }
    }

    if (_vec.size() == count) return true;
    else return false;
   


}

bool Check()
{
    vector<int> A, B;

    for (int i = 1; i <= N; i++)
    {
        if (isSelect[i]) A.push_back(i);
        else B.push_back(i);
    }

    if (A.size() == 0 || B.size() == 0) return false;

  
    bool AConnect = Connect_Check(A, true);
    if (!AConnect) return false;

    bool BConnect = Connect_Check(B, false);
    if (!BConnect) return false;

    return true;
    
}

void Calculate()
{
    int a = 0, b = 0;
    for (int i = 1; i <= N; i++)
    {
        if (isSelect[i]) a += Town_Population[i];
        else b += Town_Population[i];
    }

    min_sum = min(min_sum, abs(a - b));
}

void DFS(int _num, int _count)
{
    if (_count >= 1)
    {
        if (Check())
        {
            //계산하기.
            Calculate();
        }
    }

    for (int i = _num; i <= N; i++)
    {
        if (isSelect[i]) continue;
        isSelect[i] = true;
        DFS(i, _count + 1);
        isSelect[i] = false;
    }
}

void Slove()
{
    DFS(1, 0);

    if (min_sum == MAX) cout << -1 << endl;
    else cout << min_sum << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init(); 
    Slove();

}
