
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
    int left = 0, right = 0;
    int sum = 0;

    while (right <= N)
    {

        if (sum >= S)
        {
            sum -= vec[left];
            min_count = min(min_count, right - left);
            left++;
        }
        else
        {
            sum += vec[right];
            right++;
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
    if (min_count == MAX)
        cout << 0 << endl;
    else
        cout << min_count << endl;
}
