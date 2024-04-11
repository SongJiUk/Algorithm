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

bool DP[101];
string s;
int N;
vector<string> vec;

void Input()
{
    cin >> s;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        vec.push_back(str);
    }
}

void Init()
{
}

void Slove()
{
    int start = 0;
    for(int i =0; i<s.length(); i++)
    {
        if(DP[i] || i == 0) start = i;

        for(int j = 0; j<N; j++)
        {
            if(start + vec[j].length() > s.length()) continue;

            bool isSame = true;
            string str = vec[j];
            for(int k = 0; k< str.length(); k++)
            {
                if(str[k] != s[start + k])
                {
                    isSame = false;
                    break;
                }
            }

            if(isSame) DP[start + str.length()] = true;
        }
    }

    if(DP[s.length()]) cout << 1 << endl;
    else cout << 0 << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
