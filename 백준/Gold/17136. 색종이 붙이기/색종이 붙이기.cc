
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

int MAPS[10][10];
bool isVisit[10][10];
int counts[6] = {0, 5, 5, 5, 5, 5};
queue<pair<int, int>> q;
vector<pair<int, int>> vec;
int min_count = MAX;

void Slove();

bool Check(int _x, int _y, int _size)
{
    for (int i = _x; i < _x + _size; i++)
    {
        for (int j = _y; j < _y + _size; j++)
        {
            if (MAPS[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool rangeCheck(int _x, int _y)
{
    if(_x <= 10 && _y <=10) return true;
    
    return false;
}

void fill(int _x, int _y, int _size, int _value)
{
    for (int i = _x; i < _x + _size; i++)
    {
        for (int j = _y; j < _y + _size; j++)
        {
            MAPS[i][j] = _value;
        }
    }
}

bool Check_All_0()
{
    for(int i =0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            if(MAPS[i][j] == 1) return false;
        }
    }

    return true;
}



void DFS(int _count)
{
    if(_count > min_count) return;

    if(Check_All_0())
    {
        min_count = min(min_count, _count);
        return;
    }

    for(int i =0; i< 10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            if(MAPS[i][j]== 1)
            {
                for(int k = 5; k > 0; k--)
                {
                    if(counts[k] > 0 && Check(i,j,k) && rangeCheck(i +k, j +k))
                    {

                        counts[k]--;
                        fill(i,j,k,0);

                        DFS(_count + 1);

                        counts[k]++;
                        fill(i,j,k,1);
                    }
                }
                return;
            }
        }
    }
    
}
void Input()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> MAPS[i][j];
        }
    }
}

void Init()
{
}

void Slove()
{
    DFS(0);
    if (min_count == MAX)
        cout << -1 << endl;
    else
        cout << min_count << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();
    Slove();
}
