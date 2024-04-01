
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

int N, K;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<bool> isVisit(100001, false);
vector<int> vec;

void Input()
{
    cin >> N >> K;
}

void Init()
{
    pq.push({0, N});
}

void Slove()
{

    if (N >= K)
    {
        cout << N - K << endl;
        cout << 1 << endl;
    }
    else
    {
        int standard = MAX;
        while (!pq.empty())
        {
            int count = pq.top().first;
            int num = pq.top().second;
            pq.pop();

            isVisit[num] = true;

            if (num == K)
            {
                vec.push_back(count);
                isVisit[K] = false;
                continue;
            }

            if (num * 2 - 1 <= K && !isVisit[num * 2])
                pq.push({count + 1, num * 2});

            if (num + 1 <= K && !isVisit[num + 1])

                pq.push({count + 1, num + 1});
            if (num - 1 > 0 && num - 1 <= K && !isVisit[num - 1])
                pq.push({count + 1, num - 1});
        }

        cout << vec[0] << endl;

        int counts = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == vec[0])
                counts++;
        }

        cout << counts << endl;
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
