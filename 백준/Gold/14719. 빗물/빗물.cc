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

int H, W;
vector<int> vec;
void Input()
{
    cin >> H >> W;

    for (int i = 0; i < W; i++)
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
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {

        int left = -1;
        int right = -1;
        // 좌측
        for (int j = i; j >= 0; j--)
        {
            if (i == j)
                continue;

            if (vec[j] > left && vec[j] > vec[i])
                left = vec[j];
        }

        // 우측
        for (int j = i; j < vec.size(); j++)
        {
            if (i == j)
                continue;

            if (vec[j] > right && vec[j] > vec[i])
                right = vec[j];
        }

        if (left == -1 || right == -1)
            continue;

        if (left >= right)
            sum += right - vec[i];
        else
            sum += left - vec[i];
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
