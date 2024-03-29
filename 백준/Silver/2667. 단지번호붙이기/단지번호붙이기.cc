
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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct House
{
    int number, x, y;
    House(int _number, int _x, int _y) : number(_number), x(_x), y(_y) {}
};

struct cmp
{
    bool operator()(House &a, House &b)
    {
        return a.number <= b.number;
    }
};

int MAPS[26][26];
bool isVisit[26][26];
int N;
priority_queue<House, vector<House>, cmp> pq;
vector<int> vec;
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            MAPS[i][j] = s[j] - '0';
            if (MAPS[i][j] == 1)
                pq.push(House(0, i, j));
        }
    }
}

void Init()
{
}

void Slove()
{
    int townNum = 0;
    int count = 1;
    while (!pq.empty())
    {
        int number = pq.top().number;
        int x = pq.top().x;
        int y = pq.top().y;
        pq.pop();

        if(isVisit[x][y]) continue;

        if (number == 0 && MAPS[x][y] == 1)
        {
            count++;
            townNum++;
        }

        MAPS[x][y] = count;
        isVisit[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && MAPS[nx][ny] == 1)
            {
                MAPS[nx][ny] = count;
                pq.push(House(1, nx, ny));
            }
        }
    }

    for (int i = 2; i < 2 + townNum; i++)
    {
        int counts = 0;
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (MAPS[x][y] == i)
                    counts++;
            }
        }

        vec.push_back(counts);
    }
    sort(vec.begin(), vec.end());

    cout << townNum << endl;
    for(int i =0; i<vec.size(); i++)
    {
        cout << vec[i] << endl;
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
