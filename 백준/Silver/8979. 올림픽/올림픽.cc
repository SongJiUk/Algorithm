#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

class medal
{
public:
    medal(int _gold, int _silver, int _bronze)
    {
        gold = _gold;
        silver = _silver;
        bronze = _bronze;
    }

    int gold = 0;
    int silver = 0;
    int bronze = 0;
};
int N, K;

vector<pair<int, medal>> vec;
bool isSame[1000];
int ranks[1000] = {1,};
bool cmp(pair<int, medal> a, pair<int, medal> b)
{
    if (a.second.gold == b.second.gold && a.second.silver == b.second.silver && a.second.bronze == b.second.bronze)
    {
        isSame[a.first] = true;
        isSame[b.first] = true;
        return a.first < b.first;
    }

    if (a.second.gold == b.second.gold && a.second.silver == b.second.silver)
        return a.second.bronze > b.second.bronze;

    if (a.second.gold == b.second.gold)
        return a.second.silver > b.second.silver;

    return a.second.gold > b.second.gold;
}

void Input()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int num, G, S, B;
        cin >> num >> G >> S >> B;
        vec.push_back({num, medal(G, S, B)});
    }
}

void Init()
{
    sort(vec.begin(), vec.end(), cmp);
    for(int i =0; i<1000; i++)
    {
        ranks[i] = 1;
    }
}

void Slove()
{
    int sameNum = 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (isSame[vec[i].first] && isSame[vec[i + 1].first])
        {
            ranks[vec[i+1].first] = ranks[vec[i].first];
        }
        else
        {
            if(ranks[vec[i].first] == 1) ranks[vec[i].first] = i + 1;
            ranks[vec[i+1].first] = i + 2;
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

    cout << ranks[K] << endl;
}
