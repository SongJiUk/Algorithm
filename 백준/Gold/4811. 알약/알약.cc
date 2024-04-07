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
#include <limits.h>
#include <cmath>
#include <list>

typedef long long ll;
#define endl '\n'
#define MAX 1e9
using namespace std;

ll DP[31][31];
int N;

ll recursion(int i, int j)
{
    if(DP[i][j] == 0)
    {
        if(j > 0) DP[i][j] += recursion(i, j-1);

        if(i > 0) DP[i][j] += recursion(i-1, j+1);
    }
    
    return DP[i][j];
}

void Input()
{
    DP[0][0] = 1;
    while(true)
    {
        int x;
        cin >> x;
        if(x==0) break;
        
        cout << recursion(x-1, 1) << endl;
    }
}


void Init()
{

}

void Slove()
{
   
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    //Init();
    Slove();
}
