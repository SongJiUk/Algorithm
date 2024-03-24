#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <math.h>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;
string s;
void Input()
{
    cin >> s;
}

void Init()
{
}
void Slove()
{
    for (int i = 0; i < s.size(); i++)
    {
        bool isFour = true;
        bool isTwo = true;
        for (int a = i; a < i + 4; a++)
        {
            if(a > s.size())
            {
                isFour = false;
                break;
            }
            if (s[a] == '.')
            {
                isFour = false;
                break;
            }
            if (s[a] != 'X')
            {
                isFour = false;
                break;
            }
        }

        if (isFour)
        {

            for (int a = i; a < i + 4; a++)
            {
                s[a] = 'A';
            }
        }

        for (int b = i; b < i + 2; b++)
        {
            if(b >s.size())
            {
                isTwo = false;
                break;
            }
            if (s[b] == '.')
            {
                isTwo = false;
                break;
            }
            if (s[b] != 'X')
            {
                isTwo = false;
                break;
            }
        }

        if (isTwo)
        {

            for (int b = i; b < i +2; b++)
            {
                s[b] = 'B';
            }
        }
    }

    bool isOver =false;
    for(int i =0; i<s.size(); i++)
    {
        if(s[i] == 'X')
        {
            isOver = true;
            break;
        }
    }

    if(isOver) cout << -1 << endl;
    else cout << s << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
