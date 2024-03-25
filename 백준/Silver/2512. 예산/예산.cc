#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <math.h>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N, M;
vector<int> vec;
int max_num = 0;

void binary_search(int _left, int _right)
{

    while (_left <= _right)
    {
        int mid = (_left + _right) / 2;

        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (vec[i] > mid)
            {
                sum += mid;
            }
            else
            {
                sum += vec[i];
            }
        }

        if (sum == M)
        {
            max_num = mid;
            break;
        }
        else if (sum > M)
            _right = mid - 1;
        else
        {
            _left = mid + 1;
            max_num = max(max_num, mid);
        }
    }
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
    cin >> M;
}

void Init()
{
    sort(vec.begin(), vec.end());
}

void Slove()
{
    binary_search(0, vec[N - 1]);
    cout << max_num << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
