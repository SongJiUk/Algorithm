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

int N, K, D;
int A[10001];
int B[10001];
int C[10001];
vector<int> vec;
void Input()
{
    cin >> N >> K >> D;

    for (int i = 0; i < K; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }
}

void Init()
{
}

int Calculate(int _index)
{
    return _index + 1;
}

void Slove()
{
    int left = 0, right = N;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        ll sum = 0;
        for (int i = 0; i < K; i++)
        {
            if (mid < A[i])
                continue;

            sum += (min(mid, B[i]) - A[i]) / C[i] + 1;
        }

        if (sum >= D)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
