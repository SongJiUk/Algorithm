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

int p, m;

vector<vector<pair<int, string>>> vec;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.second < b.second;
}

void Input()
{
    cin >> p >> m;

    for (int i = 0; i < p; i++)
    {
        int l;
        string n;
        cin >> l >> n;
        
        vector<pair<int, string>> v;
        v.push_back({l,n});
        bool isFind = false;

        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j][0].first - 10 <= l && vec[j][0].first + 10 >= l)
            {
                if (vec[j].size() < m)
                {
                    vec[j].push_back({l, n});
                    isFind = true;
                    break;
                }
            }
        }

        if (!isFind)
        {
            vec.push_back(v);
        }
    }
}

void Init()
{
}

void Slove()
{
    for (int i = 0; i < vec.size(); i++)
    {
        sort(vec[i].begin(), vec[i].end(), cmp);

        if (vec[i].size() == m)
        {
            cout << "Started!" << endl;
            for (int j = 0; j < vec[i].size(); j++)
            {
                cout << vec[i][j].first << " " << vec[i][j].second << endl;
            }
        }
        else
        {
            cout << "Waiting!" << endl;
            for (int j = 0; j < vec[i].size(); j++)
            {
                cout << vec[i][j].first << " " << vec[i][j].second << endl;
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
}
