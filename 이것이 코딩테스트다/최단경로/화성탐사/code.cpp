#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int map[126][126];
int d[126][126];

int main(void) {
    int T, N;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    cin >> T;

    for(int t = 0; t< T; t ++)
    {
        cin >> N;
        for(int i =0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                int x;
                cin >> x;
                map[i][j] = x;
            }
        }

        for(int i =0; i<N; i++)
        {
            fill(d[i], d[i]+125, INF);
        }

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        int x = 0;
        int y = 0;
        pq.push({map[x][y], {0 ,0 }});
        d[x][y] = map[x][y];

        

        while(!pq.empty())
        {
            int dist = pq.top().first;
            x = pq.top().second.first;
            y = pq.top().second.second;

            pq.pop();

            // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
            if(d[x][y] < dist) continue;

            for(int i =0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx <N && ny >= 0 && ny < N)
                {
                    int cost = dist + map[nx][ny];

                    // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
                    if(cost < d[nx][ny]) 
                    {
                        d[nx][ny] = cost;
                        pq.push({cost, {nx, ny}});
                    }
                }
            }
        }
        cout << d[N-1][N-1] << endl;
    }    
}
