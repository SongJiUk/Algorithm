#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <string>

typedef long long ll;

#define endl '\n'
#define MAX 1e12
using namespace std;

vector<long long> vec;
int N, M;
long min_tree = 0;
long long height = 0;

bool compare(long long a, long long b)
{
    return a < b;
}

long long TreeCut(long long _m)
{
    long long num = 0;
    for (int i = 0; i < N; i++)
    {
        if (vec[i] > _m)
            num += vec[i] - _m;
    }

    return num;
}

int binary_searchs(long long _target, long long _left, long long _right)
{
    while (_left <= _right)
    {
        long long mid = (_left + _right) / 2;

        // 자른 나무의 합.
        long long tree_sum = TreeCut(mid);

        // 자른 나무의 합이 타겟과 같으면 해당 높이 반환
        if (tree_sum == _target)
            return mid;
        else if (tree_sum > _target)
        {
            if(min_tree > tree_sum)
            {
                min_tree = tree_sum;
                height = mid;
            }
            else
            {
                min_tree = tree_sum;
                height = mid;
            }

            _left = mid + 1;
        }
        else
        {
            if (min_tree < tree_sum)
            {
                min_tree = tree_sum;
                height = mid;
            }
            _right = mid - 1;
        }
    }

    return height;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());

    cout << binary_searchs(M, 0, vec[vec.size() - 1]) << endl;
}
