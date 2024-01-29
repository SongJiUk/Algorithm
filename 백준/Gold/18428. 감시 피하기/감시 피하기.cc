#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

char maps[6][6];

int dx[] = {0, 0, -1 ,1};
int dy[] = {-1, 1, 0, 0};

vector<pair<int,int>> teacher;
int N;
bool isPossible = false;

bool CheckTeacher()
{
    for(int i =0; i< teacher.size(); i++)
    {
        for(int k =0; k<4; k++)
        {
            for(int j = 1; j<N; j++)
            {
                
                int nx = teacher[i].first + (dx[k] * j);
                int ny = teacher[i].second + (dy[k] * j);

                if(nx < 0 || nx >= N || ny < 0 || ny >= N) break;

                if(maps[nx][ny] == 'O') break;

                if(maps[nx][ny] == 'S') return false;

                
            }
        }
    }

    return true;
}

void DFS(int _count)
{
    if(_count == 3) 
    {
        if(CheckTeacher())
        {
            isPossible = true;
            return;
        }
    }
    else
    {  
        for(int i =0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(maps[i][j] == 'X') 
                {
                    maps[i][j] = 'O';
                    _count++;
                    
                    DFS(_count);

                    maps[i][j] = 'X';
                    _count--;
                }
            }
        }
    }

}

int main() {

    
    
    cin >> N;

    for(int i =0; i<N; i++)
    {
        for (int j = 0; j<N; j++)
        {
            char x;
            cin >> x;

            maps[i][j] = x;
            
            if(x == 'T') teacher.push_back({i,j});
        }
    }

    DFS(0);
    
    if(isPossible) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}