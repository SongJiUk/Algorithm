
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
list<char> l;

string s;
int N;
void Input()
{
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        l.push_back(s[i]);
    }
    auto cur = l.end();

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char c1, c2;

        cin >> c1;

        if (c1 == 'P')
        {
            cin >> c2;
            l.insert(cur, c2);
        }
        else if (c1 == 'L')
        {
            if (cur != l.begin())
                cur--;
        }
        else if (c1 == 'D')
        {
            if (cur != l.end())
                cur++;
        }
        else if (c1 == 'B')
        {
            if (cur != l.begin())
            {
                cur--;
                cur = l.erase(cur);
            }
        }
    }
}

void Init()
{
}

void Slove()
{
    for (auto answer : l)
    {
        cout << answer;
    }
    cout << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
