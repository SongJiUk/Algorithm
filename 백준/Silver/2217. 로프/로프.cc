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

int N, max_num = 0;
vector<int> vec;

bool cmp(int a, int b)
{
    return a > b;
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
}

void Init()
{
    sort(vec.begin(), vec.end());
}

void Slove()
{
    int min_count = 0;
    int max_count = 0;
    for(int i =0; i<N; i++)
    {
        int count = 0;
        for(int j = i; j<N; j++)
        {
            min_count = vec[i];
            count += min_count;
        }
        max_count = max(max_count, count);
    }

    cout << max_count << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
