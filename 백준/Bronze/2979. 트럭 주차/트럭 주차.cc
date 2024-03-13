#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int num[101];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    vector<pair<int, int>> vec;
    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }
    
    int max_end = 0;
    for (int i = 0; i < 3; i++)
    {
        int start = vec[i].first;
        int end = vec[i].second;
        max_end = max(max_end, end);
        for (int j = start + 1; j <= end; j++)
        {
            num[j]++;
        }
    }

    for (int i = 0; i <= max_end; i++)
    {
        switch (num[i])
        {
        case 1:
            sum += A * 1;
            break;

        case 2:
            sum += B * 2;
            break;
        case 3:
            sum += C * 3;
            break;
        }
    }

    cout << sum << endl;
}
