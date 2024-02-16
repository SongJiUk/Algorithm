#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int,int>> human_que;
queue<pair<int,int>> fire_que;
char maps[1001][1001];
int human_map[1001][1001];
int fire_map[1001][1001];

int R,C;


void Fire()
{
     //불의 길
    while(!fire_que.empty())
    {   
        int x = fire_que.front().first;
        int y = fire_que.front().second;
        fire_que.pop();

        
        for(int i =0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(maps[nx][ny] == '#' || fire_map[nx][ny] >= 0) continue;

            fire_map[nx][ny] = fire_map[x][y] + 1;
            fire_que.push({nx, ny});
        }
    }
}

int Human()
{
    //지훈이 길
    while(!human_que.empty())
    {
        int x = human_que.front().first;
        int y = human_que.front().second;

        human_que.pop();
        

        for(int i =0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) return human_map[x][y] + 1;

            //방문했거나 벽일경우
            if(human_map[nx][ny] >= 0 || maps[nx][ny] == '#') continue;
            //불이 퍼진곳, 불퍼진시간보다 크면 못감
            if(fire_map[nx][ny] != -1 && fire_map[nx][ny] <= human_map[x][y] + 1) continue;

            human_map[nx][ny] = human_map[x][y] + 1;
            human_que.push({nx,ny});
        }
    }
    return -1;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
		fill(human_map[i], human_map[i] + C, -1);
		fill(fire_map[i], fire_map[i] + C, -1);
	}
    
    for(int i =0; i<R; i++)
    {
        for(int j =0; j<C; j++)
        {
            cin >> maps[i][j];

            if(maps[i][j] == 'J') 
            {
                human_map[i][j] = 0;
                human_que.push({i,j});
            }
            else if(maps[i][j] == 'F')
            {
                fire_map[i][j] = 0;
                fire_que.push({i,j});
            }
        }
     
    }

    Fire();
    int mCount = Human();

    if(mCount == -1) cout << "IMPOSSIBLE" << endl;
    else cout << mCount << endl;
}