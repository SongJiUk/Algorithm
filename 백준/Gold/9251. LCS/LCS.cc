#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

string str1, str2;
int DP[1001][1001];
int max_conut = 0;
void Input()
{  
    cin >> str1;
    cin >> str2;
}

void Init()
{
}

void Slove()
{
    for(int i =1; i<=str1.size(); i++)
    {
        for(int j = 1; j<=str2.size(); j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();

    cout << DP[str1.size()][str2.size()] << endl;

}
