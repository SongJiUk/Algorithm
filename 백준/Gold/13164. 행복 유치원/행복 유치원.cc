
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
vector<int> vec;
vector<int> v;
int N, S;
int min_count = MAX;

void Input()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
}

void Init()
{
}

void Slove()
{
    for (int i = vec.size() - 1; i > 0; i--)
    {
        v.push_back(vec[i] - vec[i - 1]);
    }
    sort(v.begin(), v.end());

    for(int i =0; i<S-1; i++)
    {
        v.pop_back();
    }

    int sum = 0;

    for(int i =0;i<v.size(); i++)
    {
        sum += v[i];
    }

    cout << sum << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
