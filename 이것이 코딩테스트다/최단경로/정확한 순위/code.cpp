
#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int n,m;
int student[501][501];

int main(void) {


    cin >> n >> m;

     for(int i = 0; i< 501; i++)
    {
        fill(student[i], student[i]+501, INF);
    }


    for(int i =1; i<=n; i++)
    {
        for(int j =1; j<=n; j++)
        {
            if(i == j) student[i][j] = 0;
        }
    }


    for(int i =0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        student[a][b] = 1;
    }


    for(int k = 1; k<=n; k++)
    {
        for(int a = 1; a<=n; a++)
        {
            for(int b =1; b<=n; b++)
            {
                student[a][b] = min(student[a][b], student[a][k] + student[k][b]);
            }
        }
    }

    int count, result = 0;
    for(int i = 1; i<=n; i++)
    {
        count = 0;
        for(int j =1; j<=n; j++)
        {
            if(student[i][j] != INF || student[j][i] != INF)
            {
                count+=1;
            }
        }
        if(count == n) result+=1;
    }

    cout << result << endl;
}  
