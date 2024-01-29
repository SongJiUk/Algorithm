#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 1e9
using namespace std;

int maps[101][101];
int defaultDir = 3;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {

    int N, K;
    cin >> N;
    cin >> K;


    for(int i =0; i<101; i++)
    {
        fill(maps[i], maps[i]+101, INF);
    }


    for(int i =0; i<K; i++)
    {
        int a, b;
        cin >> a >> b;
        maps[a][b] = 0;
    }

    int L;
    
    queue<pair<int, char>> q;
    cin >> L;
    for(int i =0; i<L; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        q.push({a,b});
    }


    int time = 0;
    int length = 1;
    int x = 1, y = 1;
    queue<pair<int,int>> que;
    que.push({1,1});

    while(true)
    {
        
        int nx = x + dx[(defaultDir % 4 + 4) % 4];
        int ny = y + dy[(defaultDir % 4 + 4) % 4];


        if(nx <= 0 || nx > N || ny <= 0 || ny > N || maps[nx][ny] == 1) //벽이거나, 자신의 몸일경우
        {
            time++;
            break;
        }
        else if(maps[nx][ny] == INF) //그냥 길일경우.
        {
            
            int beforeX = 0;
            int beforeY = 0;
            
            for(int i =1; i<=length; i++)
            {

                if(i == 1) // 머리부분만
                {
                    beforeX = que.front().first;
                    beforeY = que.front().second;
                    maps[beforeX][beforeY] = INF;
                    maps[nx][ny] = 1;
                    x = nx;
                    y = ny;
                    que.push({x, y});
                }
                else
                {
                    maps[beforeX][beforeY] = 1;
                    que.push({beforeX, beforeY});
                    beforeX = que.front().first;
                    beforeY = que.front().second;
                    maps[beforeX][beforeY] = INF;
                }

               que.pop();

            }     
        }
        else if(maps[nx][ny] == 0) //사과 일경우
        {
            length++;
            que.push({nx,ny});
            x = nx;
            y = ny;
            for(int i =1; i<length; i++)
            {
                int beforeX = que.front().first;
                int beforeY = que.front().second;
                que.pop();

                que.push({beforeX, beforeY});                

            }

        }

        time++;
        
        //시간 맞으면 방향 바꿔주기
        if(!q.empty() && q.front().first == time)
        {
            switch (q.front().second)
            {
            case 'L' :
                defaultDir--;
                break;
            
            case 'D' :
                defaultDir++;
                break;
            }

            q.pop();
        }
    }


    cout << time << endl;
    return 0;
}