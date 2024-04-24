
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
#include <regex>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;
int V, E, sum;
int parent[10001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
vector < pair<int, pair<int, int>>> vec;
bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b)
{
    return a.first < b.first;
}

int Find(int _x)
{
    if (parent[_x] == _x) return _x;
    else return parent[_x] = Find(parent[_x]);
}

void Union(int _x, int _y)
{
    _x = Find(_x);
    _y = Find(_y);


    if (_x < _y) parent[_y] = _x;
    else parent[_x] = _y;

}

void Input()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        pq.push({ C,{A,B} });
        vec.push_back({ C,{A,B} });
    }
}

void Init()
{
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    sort(vec.begin(), vec.end(), cmp);

}



void Slove()
{
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int cost = vec[i].first;
        int x = vec[i].second.first;
        int y = vec[i].second.second;

        //사이클이면 x
        if (Find(x) == Find(y)) continue;

        Union(x, y);

        sum += cost;
        count++;

        if (count == V - 1) break;
    }

    cout << sum << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init(); 
    Slove();

}
