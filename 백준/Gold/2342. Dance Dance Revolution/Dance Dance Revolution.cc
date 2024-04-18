
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

//int DP[100001][5][5];
vector<vector<vector<int>>> DP(100001, vector<vector<int>>(5, vector<int>(5, MAX)));
int counts;

// 하나 알게된 사실. 3차원배열을 초기화할때는 0.3f로 하면 memset을 이용할 수 있음.
int Get_Power(int _before, int _after)
{   
    // 0 -> 다른수갈때는 2
    if (_before == 0) return 2;

    // 같은곳은 1
    if (_before == _after) return 1;

    // 1 ->2,4 2 ->1,3 3 ->2,4 4 -> 1,3 갈때는 2
    // 1 ->3 2 ->4, 3 ->1, 4 ->2 는 4
    if (abs(_before - _after) == 2) return 4;

    return 3;
}


void Input()
{
    
    DP[0][0][0] = 0;
    counts = 0;
   

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        
        counts++;

        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (DP[counts - 1][x][y] == MAX) continue;

                //오른발
                DP[counts][x][n] = min(DP[counts][x][n], DP[counts - 1][x][y] + Get_Power(y, n));

                //왼발
                DP[counts][n][y] = min(DP[counts][n][y], DP[counts - 1][x][y] + Get_Power(x, n));
            }
        }

    }

}

void Init()
{

}



void Slove()
{
    int min_num = MAX;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
             min_num = min(min_num, DP[counts][i][j]);
        }
    }
    cout << min_num << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init(); 
    Slove();

}
