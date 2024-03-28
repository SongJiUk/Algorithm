
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

int N;
vector<bool> vec(500001, false);
stack<int> s;
vector<int> v;
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(y);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        s.push(v[i]);
    }
}

void Init()
{
}

void Slove()
{
    int count = 0;
    while (!s.empty())
    {
        int num = s.top();
        s.pop();

        if(num == 0) continue;
        
        if (s.size() > 1)
        {
            if (num != s.top() && !vec[num])
            {
                vec[num] = true;
                count++;
            }

            if (num > s.top())
            {
                for (int i = s.top() + 1; i <= num; i++)
                {
                    vec[i] = false;
                }
            }
        }
        else
        {
            if(!vec[num]) count++;
        }   
    }
    cout << count << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
