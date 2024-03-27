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

int N;
vector<int> vec(11);
vector<int> order(11, 10);

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> vec[i];
    }
}

void Init()
{
}

void Slove()
{
    for (int i = 1; i <= N; i++)
    {
        int num = vec[i];
        int count = 0;
        for (int j = 1; j <= N; j++)
        {
            if (count == num && order[j] == 10)
            {
                order[j] = i;
                break;
            }
            if (i < order[j])
                count++;
        }
    }   

    for (int i = 1; i <= N; i++)
    {
        cout << order[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
}
