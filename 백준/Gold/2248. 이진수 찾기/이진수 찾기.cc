#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N, L;
ll I;

ll DP[33][33];
string s;

queue<pair<int,pair<int,ll>>> que;

void find_number()
{
    while(!que.empty())
    {    
        int _N = que.front().first;
        int _L = que.front().second.first;
        ll _I = que.front().second.second;

        que.pop();
        if(_N == 0) break;
        if(_L == 0)
        {   
            for(int i =0; i<_N; i++) s += '0';
            break;
        }

        ll sum = 0;

        for(int i = 0; i<=_L; i++)
        {
            sum += DP[_N - 1][i];
        }


        if(sum >= _I)
        {
            s += '0';
            que.push({_N-1,{_L, _I}});
        }
        else
        {
            s+= '1';
            que.push({_N-1,{_L-1, _I - sum}});
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> N >> L >> I;

    
   DP[0][0] = 1;
   for(int i =1; i<=N; i++)
   {
        DP[i][0] = 1;
        DP[i][i] = 1;
   }

    for(int i =2; i<= N; i++)
    {   
        for(int j =1; j<=i; j++)
        {
            DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
        }
    }

    que.push({N,{L, I}});
    find_number();

    cout << s << endl;
}
