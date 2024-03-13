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

int DP[1001];
int max_count = 0;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> vec(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> vec[i];
    }
    // 뒤에서부터 하는게 낫나? --> DP의 값도 기록해주면 됨.(DP엔 순서를 넣자)
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (vec[j] < vec[i] && DP[i] < DP[j] + 1)
            {
                DP[i] = DP[j] + 1;
            }
        }
        max_count = max(max_count, DP[i]);
    }

    cout << max_count << endl;

    stack<int> s;
    for (int i = N; i > 0; i--)
    {
        if (DP[i] == max_count)
        {
            s.push(vec[i]);
            max_count--;
        }
    }

    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
