#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 1e9
using namespace std;

vector<pair<int,int>> vec[20001];
int Adist[20001];

int start =1;


void dijkstra(int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    Adist[start] = 0;


    while(!pq.empty())
    {
        int pq_cost = pq.top().first;
        int pq_now = pq.top().second;

        pq.pop();

        if(Adist[pq_now] < pq_cost) continue;

        for(int i =0; i< vec[pq_now].size(); i++)
        {
            int dist = pq_cost + vec[pq_now][i].second;

            if(dist < Adist[vec[pq_now][i].first])
            {
                Adist[vec[pq_now][i].first] = dist;
                pq.push({dist, vec[pq_now][i].first});
            }
        }
    }
}


int main() {
   
   int N, M;

   cin >> N >> M;

   for(int i =0; i<M; i++)
   {
        int a,b;
        cin >> a >> b;
        vec[a].push_back({b,1});
        vec[b].push_back({a,1});
   }


    fill(Adist, Adist + 20001, INF);
    

    dijkstra(start);

    //헛간번호, 거리, 헛간의 개수
    int num =0, distance =0, count;

    for(int i = 1; i<=N; i++)
    {
        if(distance < Adist[i])
        {
            num = i;
            distance = Adist[i];
            count = 1;
        }
        else if(distance == Adist[i])
        {
            count++;
        }
    }

    cout << num << " " << distance << " " << count << endl;
    return 0;
}
