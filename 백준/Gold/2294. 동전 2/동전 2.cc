
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

int n, k;
vector<int> vec;
priority_queue<pair<int, int>> pq;
int min_count = MAX;
int DP[10001];
void Input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
        pq.push({1, x});
    }
}

void Init()
{
    for (int i = 0; i <= 10001; i++)
    {
        DP[i] = MAX;
    }
    DP[0] = 0;
    sort(vec.begin(), vec.end());
    int count = 0;
    for (int i = vec[0]; i <= 10001;)
    {
        count++;
        DP[i] = count;
        i += vec[0];
    }
}

void Slove()
{
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (i < vec[j])
                break;

            DP[i] = min(DP[i], DP[i - vec[j]] + 1);
        }
    }

    if(DP[k] == MAX) cout << -1 << endl;
    else cout << DP[k] << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
