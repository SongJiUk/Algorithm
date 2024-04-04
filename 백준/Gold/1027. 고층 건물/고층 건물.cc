
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
vector<int> vec(51);

int N;
int max_count = 0;
double inclination(int x1, int x2, int y1, int y2)
{
    double num = (double)(y2 - y1) / (double)(x2 - x1);
    return num;
}

// 기울기 공식은 y2 -y1 / x2-x1
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
        int count = 0;
        double num = 0;
        // 우
        for (int j = i + 1; j <= N; j++)
        {
            // 첫번째값은 무조건 보이니까.
            if (j == i + 1)
            {
                num = inclination(i, j, vec[i], vec[j]);
                count++;
                continue;
            }
                

            if (num < inclination(i, j, vec[i], vec[j]))
            {
                num = inclination(i, j, vec[i], vec[j]);
                count++;
            }
        }

        // 좌
        for (int j = i - 1; j > 0; j--)
        {
            if (j == i - 1)
            {
                num = inclination(i, j, vec[i], vec[j]);
                count++;
                continue;
            }
                

            if (num > inclination(i, j, vec[i], vec[j]))
            {
                num = inclination(i, j, vec[i], vec[j]);
                count++;
            }
        }

        max_count = max(max_count, count);
    }

    cout << max_count << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
