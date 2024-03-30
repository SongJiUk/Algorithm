
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

string s;
const int Plus = 13;

void Input()
{
    getline(cin, s);
}

void Init()
{
}

void Slove()
{
    for (int i = 0; i < s.size(); i++)
    {
        if (int(s[i]) == 32)
            continue;

        // 대문자
        if (int(s[i]) >= 65 && int(s[i]) <= 90)
        {
            int num = int(s[i]) + Plus;
            if (num > 90)
            {
                num = (num % 90) + 64;
            }

            s[i] = num;
        }

        // 소문자
        if (int(s[i]) >= 97 && int(s[i] <= 122))
        {
            int num = int(s[i]) + Plus;
            if (num > 122)
            {
                num = num % 122 + 96;
            }

            s[i] = num;
        }
    }

    cout << s << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
