#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
#define MAX 1e9
using namespace std;



int N, M, H;
int min_width = MAX;
bool Check(vector<vector<int>>& _vec)
{
    //사다리타기 게임이니까 해당 이차원벡터에 
    //0이 들어있으면, x값 +1, 1이 들어있으면 y값 +1, -1이 들어있으면 y값 -1 
    for(int i = 1; i<=N; i++)
    {
        int y = i;
        int x = 1;
        while(x <= H)
        {
            if(_vec[x][y] == 1) y++;
            else if(_vec[x][y] == -1) y--;

            x++;
        }

        if(y!= i) return false;
    }
    
    return true;
}

void DFS(vector<vector<int>>& _vec, int _a, int _b, int _widthCount)
{

    if(Check(_vec))
    {
        min_width = min(min_width, _widthCount);
        return;
    }

    if(_widthCount == 3) return;
   

    for(int i = _a; i<=H; i++)
    {
        for(int j = _b; j<=N; j++)
        {
            if(_vec[i][j] == 0 && _vec[i][j+1] == 0)
            {
                _vec[i][j] = 1;
                _vec[i][j+1] = -1;
                DFS(_vec, i, 1, _widthCount +1);
                _vec[i][j] = 0;
                _vec[i][j+1] = 0;
            }
        }

    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    cin >> N >> M >> H;

    vector<vector<int>> vec(H + 1, vector<int>(N + 1, 0));
    for(int i =0; i< M; i++)
    {
        int a,b;
        cin >> a >> b;

        vec[a][b] = 1;
        vec[a][b+1] = -1;
    }

    DFS(vec, 1, 1, 0);


    if(min_width == MAX) cout << -1 << endl;
    else cout << min_width << endl;
}   
