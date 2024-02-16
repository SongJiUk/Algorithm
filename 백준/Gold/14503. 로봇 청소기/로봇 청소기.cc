#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

//싱 좌 하 우
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int cleanCount = 0;

int maps[51][51];
queue<pair<int, pair<int,int>>> q;

bool Check_FourDir(int _x, int _y)
{
    for(int i =0; i<4; i++)
    {
        int nx = _x + dx[i];
        int ny = _y + dy[i];

        if(maps[nx][ny] == 0) return true;
    }
    return false;
}

void Solution()
{
    while(!q.empty())
    {

        int dir = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if(maps[x][y] == 0) 
        {
            maps[x][y] = -1;
            cleanCount++;
        }

        if(Check_FourDir(x, y))
        {
            /*
            ! 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
            1) 반시계 방향으로 90도 회전한다.
            2) 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
            3) 1번으로 돌아간다.
            */

            //turn_left 0 -> 3 -> 2 -> 1

            dir = (dir + 3 )% 4; //회전시키고

            switch (dir)
            {
            case 0 :
                if(maps[x-1][y] == 0) q.push({dir,{x-1, y}});
                else q.push({dir ,{x, y}});
                break;
            
            case 1 :
                if(maps[x][y+1] == 0) q.push({dir,{x, y+1}});
                else q.push({dir ,{x, y}});
                break;

                
            case 2 :
                if(maps[x+1][y] == 0) q.push({dir,{x+1, y}});
                else q.push({dir ,{x, y}});
                break;
            
            case 3 :
                if(maps[x][y-1] == 0) q.push({dir,{x, y-1}});
                else q.push({dir ,{x, y}});
                break;

            }


        }
        else
        {
            /*
            ! 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
            1) 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
            2) 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
            dir 북 - 0 , 동 - 1, 남 - 2, 서 - 3
            */
            
            switch (dir)
            {
            case 0 :
                if(maps[x+1][y] == 1) return;
                else q.push({dir ,{x+1, y}});
                break;

            case 1:
                if(maps[x][y-1] == 1) return;
                else q.push({dir ,{x, y-1}});
                break;

            case 2:
                if(maps[x-1][y] == 1) return;
                else q.push({dir ,{x-1, y}});
                break;

            case 3:
                if(maps[x][y+1] == 1) return;
                else q.push({dir ,{x, y+1}});
                break;
            }   
        }
    }
}



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, r, c, dir;

    cin >> N >> M;
    cin >> r >> c >> dir;

    q.push({dir,{r,c}});

    for(int i =0; i<N; i++)
    {
        for (int j = 0; j<M; j++)
        {
            cin >> maps[i][j];
        }
    }

  
    Solution();

    
    cout << cleanCount << endl;


}