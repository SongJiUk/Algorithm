
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

struct Belt
{
    bool isOnRobot = false;
    int durability;
    Belt(bool _isOnRobot, int _durability) : isOnRobot(_isOnRobot), durability(_durability) {}
};
vector<Belt> v;
int N, K;
queue<pair<int, bool>> q;
int counts = 0;
void Input()
{
    cin >> N >> K;
    for (int i = 0; i < N * 2; i++)
    {
        int x;
        cin >> x;
        v.push_back(Belt(false, x));
    }
}

void Init()
{
}

void FindRobot()
{
    for (int i = N-2; i >= 0; i--)
    {
        if (v[i].isOnRobot)
        {
            if (v[i + 1].isOnRobot)
                continue;
            else
            {
                if (v[i + 1].durability > 0)
                {
                    v[i].isOnRobot = false;
                    v[i + 1].isOnRobot = true;
                    v[i + 1].durability--;
                    if (i + 1 == N - 1)
                    {
                        v[i + 1].isOnRobot = false;
                    }
                }
            }
        }
    }
}

int Check()
{
    counts = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].durability == 0)
            counts++;
    }

    return counts;
}
void Slove()
{
    /*
    벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
    로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
    올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
    내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
    */
    int step = 0;
    while (true)
    {
        // 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        step++;

        Belt belt = v[v.size() - 1];
        v.pop_back();
        v.insert(v.begin(), belt);

        if (v[N - 1].isOnRobot)
            v[N - 1].isOnRobot = false;
        // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        FindRobot();

        // 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if (v[0].durability > 0 && !v[0].isOnRobot)
        {
            v[0].isOnRobot = true;
            v[0].durability--;
        }

        if (Check() >= K)
            break;
    }

    cout << step << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
