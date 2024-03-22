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
stack<char> c;
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

    if(DP[str1.size()][str2.size()] == 0 )
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        cout << DP[str1.size()][str2.size()] << endl;

        int max_num = DP[str1.size()][str2.size()];
        for(int i = str1.size(); i>0; i--)
        {
            for(int j =str2.size(); j>0; j--)
            {
                if(str1[i-1] == str2[j-1])
                {
                    if(DP[i][j] == max_num)
                    {
                        c.push(str1[i-1]);
                        max_num--;
                        break;
                    }
                }
            }
        }

        for(int i =0; c.size(); i++)
        {
            cout << c.top();
            c.pop();
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
}
