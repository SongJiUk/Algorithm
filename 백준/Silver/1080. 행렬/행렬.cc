#include <iostream>

#define MAX 51
using namespace std;
int N, M;
int counts = 0;
char mapsA[MAX][MAX];
char mapsB[MAX][MAX];


void ReversMaps(int _x, int _y)
{
    for(int i = _x; i< _x +3; i++)
    {
        for(int j = _y; j < _y +3; j++)
        {
            if(mapsA[i][j] == '0') mapsA[i][j] = '1';
            else mapsA[i][j] = '0';
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int x= 0; x < N; x++)
    {
        for(int y =0; y<M; y++)
        {
            char c;
            cin >> c;
            mapsA[x][y] = c;
        }
    }

    for(int x= 0; x < N; x++)
    {
        for(int y =0; y<M; y++)
        {
            char c;
            cin >> c;
            mapsB[x][y] = c;
        }
    }


    for(int i =0; i< N-2; i++)
    {
        for(int j = 0; j< M-2; j++)
        {
            if(mapsA[i][j] != mapsB[i][j])
            {
                counts++;
                ReversMaps(i,j);
            }
        }
    }
    
    bool isNo = false;
    for(int i =0; i<N; i++)
    {
        for (int j =0; j<M; j++)
        {
            if(mapsA[i][j] != mapsB[i][j])
            {
                isNo = true;
            }
        }
    }

    if(isNo) cout << -1;
    else cout << counts;
}
