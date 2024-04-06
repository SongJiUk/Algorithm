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

int N, T, G;
queue<pair<int, int>> q;
bool isVisit[100000];
int min_count = MAX;
void Input()
{
    cin >> N >> T >> G;
}

void Init()
{
}

void Slove()
{
    int sum, mul;
    q.push({0, N});
    isVisit[N] = true;

    while (!q.empty())
    {
        int count = q.front().first;
        int num = q.front().second;
        q.pop();
        if (num == G)
        {
            cout << count << endl;
            return;
        }

        if (count >= T)
            continue;

        sum = num + 1;
        if (!isVisit[sum] && sum < 100000)
        {
            q.push({count + 1, sum});
            isVisit[sum] = true;
        }

        mul = num * 2;
        string s = to_string(mul);

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] != '0')
            {
                int tmp = s[i] - '0';
                tmp--;
                s[i] = tmp + '0';
                break;
            }
        }

        int number = stoi(s);

        if (!isVisit[number] && mul < 100000)
        {
            isVisit[number] = true;
            q.push({count + 1, number});
        }
    }
    cout << "ANG" << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
