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

int V, E, start;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Input()
{
    cin >> V >> E;
    cin >> start;
}

void Init()
{
}

void Slove()
{
    vector<vector<pair<int, int>>> vec(V + 1);
    vector<int> distance(V + 1, MAX);
    vector<bool> isVisit(V + 1, false);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }

    for (int i = 0; i < vec[start].size(); i++)
    {
        pq.push({vec[start][i].second, vec[start][i].first});
        distance[start] = 0;
        isVisit[start] = true;
    }

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int dir = pq.top().second;
        pq.pop();

        if(isVisit[dir]) continue;
        isVisit[dir] = true;

        distance[dir] = dis;
        for(int i =0; i < vec[dir].size(); i++)
        {
            pq.push({dis + vec[dir][i].second, vec[dir][i].first});
        }
    }

    for(int i =1; i<= V; i++)
    {
        if(distance[i] == MAX) cout << "INF" << endl;
        else cout << distance[i] << endl;
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
