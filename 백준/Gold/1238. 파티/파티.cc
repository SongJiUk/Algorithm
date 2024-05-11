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

vector<pair<int,int>> vec[1002];
int N, M, X;
int dist[1002];

int max_num = 0;


void Input()
{
    cin >> N >> M >> X;

    for(int i =0; i<M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        vec[a].push_back({b,c});
    }    
}

void Init()
{
}

int BFS(int _start, int _end)
{
    
    for(int i =0; i< 1002; i++)
    {
        dist[i] = MAX;
    }
    int min_num = MAX;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, _start});
    

    while(!pq.empty())
    {
        int cost = pq.top().first;
        int next = pq.top().second;
        pq.pop();


        if(next == _end)
        {
            return cost;
        }

        for(int i =0; i<vec[next].size(); i++)
        {
            if(dist[vec[next][i].first] > vec[next][i].second + cost)
            {
                dist[vec[next][i].first]  = vec[next][i].second + cost;
                pq.push({vec[next][i].second + cost, vec[next][i].first});
            }
        }
    }
    return 0;
}

void Slove()
{
    for(int i =1; i<=N; i++)
    {
        int num1 = BFS(i , X);
        int num2 = BFS(X, i);
        max_num = max(max_num, num1+num2);
    }

    cout << max_num << endl;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
