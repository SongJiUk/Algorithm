
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

typedef long long ll;
#define endl '\n'
#define MAX 1e9
using namespace std;

string DP[101];
ll minDP[101];
int T;
vector<int> vec;

void Input()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
}

void Init()
{
    DP[2] = '1';
    DP[3] = '7';

    for (int i = 4; i < 101; i++)
    {
        DP[i] = DP[i - 2] + DP[2];
    }

    for(int i =0; i<101; i++)
    {
        minDP[i] = LLONG_MAX;
    }
    
    minDP[2] = 1;
    minDP[3] = 7;
    minDP[4] = 4;
    minDP[5] = 2;
    minDP[6] = 6;
    minDP[7] = 8;
    ll minArray[8] = {0, 0, 1, 7, 4, 2, 0, 8};
    for (int i = 8; i < 101; i++)
    {
        for(int j =2; j<8; j++)
        {
            if(minDP[i-j] == LLONG_MAX) continue;

            string str1 = to_string(minDP[i-j]);
            string str2 = to_string(minArray[j]);
            
            minDP[i] = min(minDP[i], stoll(str1 + str2));    
        }
        
    }
}

void Slove()
{
    for (int i = 0; i < T; i++)
    {
        int num = vec[i];
        cout << minDP[num] << " " << DP[num] << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();

}
