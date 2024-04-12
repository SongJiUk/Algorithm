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

int dxy[4] = {-3, 3, -1, 1};
set<string> s;
queue<pair<int, pair<int, string>>> q;
string str;

void Input()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char s;
            cin >> s;
            str += s;
        }
    }
}

bool Check(string _str)
{
    if (_str == "123456780")
        return true;

    return false;
}
bool BFS()
{

    while (!q.empty())
    {
        int count = q.front().first;
        int pos = q.front().second.first;
        string str1 = q.front().second.second;
        q.pop();

        if (Check(str1))
        {
            cout << count << endl;
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int right = 8;
            int p = pos;
            if (i >= 2)
            {
                p = pos % 3;
                right = 2;
            }

            int nxy = p + dxy[i];

            if (nxy >= 0 && nxy <= right)
            {
                nxy = pos + dxy[i];

                string str2 = str1;
                char tmp = str2[pos];
                str2[pos] = str2[nxy];
                str2[nxy] = tmp;

                if (s.find(str2) == s.end())
                {
                    q.push({count + 1, {nxy, str2}});
                    s.insert(str2);
                }
                    
            }
        }
    }
    return false;
}

void Init()
{
    s.insert(str);
    int num = str.find("0");
    q.push({0, {num, str}});
}

void Slove()
{
    if (!BFS())
        cout << -1 << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
