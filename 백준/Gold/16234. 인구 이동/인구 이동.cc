#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;


int maps[51][51];
bool bVisitMap[51][51];
int N, L ,R;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void process(int _x, int _y)
{
    int count = 0;
    int sum = 0;
    queue<pair<int,int>> q;
    q.push({_x,_y});
    vector<pair<int,int>> united;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i =0; i<4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if(nx < 0 || nx >= N || ny < 0 || ny >=N) continue;
                            
            if(bVisitMap[nx][ny]) continue;

            if(abs(maps[x][y] - maps[nx][ny]) >= L && abs(maps[x][y] - maps[nx][ny]) <= R)
            {
                q.push({nx, ny});
                bVisitMap[nx][ny] = true;
                united.push_back({nx,ny});
                sum += maps[nx][ny];
                count++;
            }
        }
    }

    for(int i=0; i<united.size(); i++)
    {
        int x = united[i].first;
        int y = united[i].second;
        maps[x][y] = sum / count;
    }
}

int main() {

    
    cin >> N >> L >> R;


    for(int i =0; i<N; i++)
    {
        for(int j =0; j<N; j++)
        {
            int x;
            cin >> x;
            maps[i][j] = x;
        }
    }

    

    int day = 0;
   
    int index = 0;
    while(true)
    {
        for(int i =0; i<N; i++)
        {
            for (int j = 0; j<N; j++)
            {
                bVisitMap[i][j] = false;
            }
        }

        int index = 0; 

        for(int i =0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(!bVisitMap[i][j])
                {
                    process(i,j);
                    index++;
                }
            }
        }

        if(index == N*N) break;
        day++;
    }

    cout << day << endl;
    return 0;
}