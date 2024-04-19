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

int T;
queue<pair<int, string>> q;
bool isVisit[10000];
string Slove(int);
void Init();

void Input()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int before, after;
        cin >> before >> after;

        q = queue<pair<int, string>>();
        q.push({before, ""});

        cout << Slove(after) << endl;

        Init();
    }
}

void Init()
{
    memset(isVisit, false, sizeof(isVisit));
}

int D(int _before)
{
    // N을 두배로 바꾸고 10000이상이면  MOD 10000 해준다.
    _before *= 2;
    if (_before >= 10000)
        _before %= 10000;

    return _before;
}

int S(int _before)
{
    // N에서 1을 뺀다. 만약 N이 0이었다면, 9999로 반환.
    if (_before == 0)
        _before = 9999;
    else
        _before -= 1;

    return _before;
}

int L(int _before)
{
    return (_before % 1000) * 10 + (_before / 1000);
}

int R(int _before)
{
   return (_before / 10) + (_before % 10) * 1000;
}

string Slove(int _after)
{

    while (!q.empty())
    {
        int before = q.front().first;
        string str = q.front().second;
        q.pop();

        if (before == _after)
        {
            return str;
        }

        for (int i = 0; i < 4; i++)
        {
            string s = str;
            int after;
            switch (i)
            {
            case 0:
                after = D(before);
                if (!isVisit[after])
                {
                    q.push({after, s += 'D'});
                    isVisit[after] = true;
                }

                break;

            case 1:
                after = S(before);
                if (!isVisit[after])
                {
                    q.push({after, s += 'S'});
                    isVisit[after] = true;
                }
                break;

            case 2:
                after = R(before);
                if (!isVisit[after])
                {
                    q.push({after, s += 'R'});
                    isVisit[after] = true;
                }
                break;

            case 3:
                after = L(before);
                if (!isVisit[after])
                {
                    q.push({after, s += 'L'});
                    isVisit[after] = true;
                }
                break;
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
    // Slove();
}
