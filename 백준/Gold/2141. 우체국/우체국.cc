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

int N;
bool cmp(pair<int,int> a , pair<int,int> b)
{
    return a.first < b.first;
}
vector<pair<int,int>> vec;
ll sum;
void Input()
{
    cin >> N;
    for(int i =0; i<N; i++)
    {
        int pos, people;
        cin >> pos >> people;
        vec.push_back({pos, people});
        sum += people;
    }

    sort(vec.begin(), vec.end(), cmp);
}

void Init()
{
}

void Slove()
{
    ll pSum = 0;
    for(int i = 0; i<N; i++)
    {
        pSum += vec[i].second;
        auto a = sum/2.0;
        if(pSum >= a)
        {
            cout << vec[i].first << endl;
            break;
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
