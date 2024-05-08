
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
#define MAX 1e8
using namespace std;


int N, E, u, v;
vector<pair<int,int>> vec[802];
int dist[802];

void BFS(int);
void Input()
{
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        vec[a].push_back({ b,c });
        vec[b].push_back({ a,c });
    }

    cin >> u >> v;
}
void Init()
{
        
}



void Slove()
{
    BFS(1);
    int dist1 = dist[u];
    int dist2 = dist[v];

    BFS(u);
    int u_to_v = dist[v];
    int u_to_N = dist[N];

    BFS(v);
    int v_to_N = dist[N];

    int result = MAX;

    result = min(result, dist1 + u_to_v + v_to_N);
    result = min(result, dist2 + u_to_v + u_to_N);

    if (result >= MAX) cout << -1 << endl;
    else cout << result << endl;
}

void BFS(int _num)
{
    fill(dist, dist + 802, MAX);
    priority_queue<pair<int, int>> pq;

    pq.push({ 0, _num });
    dist[_num] = 0;
    while (!pq.empty())
    { 
        int cost = pq.top().first;
        int next = pq.top().second;
        pq.pop();

        if (dist[next] < cost) continue;

        for (int i = 0; i < vec[next].size(); i++)
        {
            int nx = vec[next][i].first;
            int ncost = cost + vec[next][i].second;

            if (dist[nx] > ncost)
            {
                pq.push({ ncost, nx });
                dist[nx] = ncost;
            }
        }
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
