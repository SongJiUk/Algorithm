
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

typedef long long ll;
#define endl '\n'
#define MAX 1e9
using namespace std;

int N;
vector<int> vec;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int min_number = INT32_MAX;

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
}

void Slove()
{
    int left = 0, right = N - 1;

    while (left < right)
    {
        int sum = vec[left] + vec[right];
        if (min_number >= abs(sum))
        {
            min_number = abs(sum);
            pq.push({abs(sum), {vec[left], vec[right]}});
        }
        if (sum == 0)
        {
            break;
        }
        else if (sum > 0)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << pq.top().second.first << " " << pq.top().second.second << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
