#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 1e9

using namespace std;

//
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pair<int , pair<int,int>>> vec;

int originmaps[51][51];
int maps[51][51];
int newMaps[51][51];
int N, M, K;
bool isCheck[6];
int order[6];
int dir = 0;
int minNum = MAX;



void turn()
{
     //가장 윗쪽칸 (r-s, c-s) 가장 오른쪽칸 (r+s, c+s)
    for(int i =0; i< K; i++)
    {
        int vec_order = order[i];
        int r = vec[vec_order].first;
        int c = vec[vec_order].second.first;
        int s = vec[vec_order].second.second;

        int leftX = r-s;
        int leftY = c-s;

        int rightX = r+s;
        int rightY = c+s;

        
        int s_size = rightX - leftX + 1;
        int square_count = s_size / 2;

        
        for(int s = 0; s < square_count; s++)
        {
            int size = s_size - (2 * s);
            int l_x = leftX + s;
            int l_y = leftY + s;
            int r_x = rightX - s;
            int r_y = rightY - s;
            dir = 0;
            
            int x = l_x;
            int y = l_y;
            for(int t = 0; t< size * 4 - 4; t++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx > r_x || nx < l_x || ny > r_y || ny < l_y)
                {
                    dir++;
                    t--;
                    continue;
                }
                newMaps[nx][ny] = maps[x][y];
                x = nx;
                y = ny;

            }
        }


        for(int a = 1; a<= N; a++)
        {
            for(int b =1; b<=M; b++)
            {
                maps[a][b] = newMaps[a][b];
            }
        }
    }

    for(int i = 1; i<=N; i++)
    {
        int num = 0;
        for(int j = 1; j<=M; j++)
        {
            num += maps[i][j];
        }

        minNum = min(minNum, num);
    }
}

void DFS(int _cnt)
{
    if(_cnt == K)
    {
        for(int a = 1; a<= N; a++)
        {
            for(int b =1; b<=M; b++)
            {
                maps[a][b] = originmaps[a][b];
                newMaps[a][b] = originmaps[a][b];
            }
        }    

        turn();
        return;
    }
    else
    {
        for (int i = 0; i < K; i++) 
        {
		    if (isCheck[i] == true) continue;
		    isCheck[i] = true;
            order[_cnt] = i;
		    DFS(_cnt + 1);
		    isCheck[i] = false;
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N >> M >> K;
    

    for(int i =1; i<=N; i++)
    {
        for(int j =1; j<=M; j++)
        {
            cin >> maps[i][j];

            newMaps[i][j] = maps[i][j];
            originmaps[i][j] = maps[i][j];
        }
    }

    for(int i = 0; i<K; i++)
    {
        int r,c,s;
        cin >> r >> c >> s;
        vec.push_back({r,{c, s}});
    }
    DFS(0);

    cout << minNum << endl;
}