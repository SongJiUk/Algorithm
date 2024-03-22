#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N, d, k, c;

vector<int> vec;
int sushi[30001];
bool isCheck[30001];
int max_count = 0;
void Input()
{
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++)
    {
        cin >> sushi[i];
    }
}

void Init()
{
}

void Slove()
{
    for (int i = 0; i < N; i++)
    {
        int count = 0;
        int coupon = 1;

        for (int j = i; j < i + k; j++)
        {
            if (!isCheck[sushi[j % N]])
                isCheck[sushi[j % N]] = true;
            else
                count++;
        }

        if (isCheck[c])
            coupon = 0;

        max_count = max(max_count, k - count + coupon);

        memset(isCheck, false, sizeof(isCheck));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();

    cout << max_count << endl;
}
