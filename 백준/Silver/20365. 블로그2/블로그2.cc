#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N;
string s;
string s1;
string s2;
int min_count = MAX;
void Input()
{
    cin >> N;
    cin >> s;
}

void Init()
{
    for (int i = 0; i < N; i++)
    {
        s1 += 'B';
        s2 += 'R';
    }
}

void Slove()
{
    int count = 1;
    int sameCount = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == s1[i])
        {
            sameCount = 0;
            continue;
        }
            
        else
        {
            if(sameCount < 1) count++;
            sameCount++;
        }
            
    }
    min_count = min(min_count, count);

    count = 1;
    sameCount = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == s2[i])
        {
            sameCount = 0;
            continue;
        }
            
        else
        {
            if(sameCount < 1) count++;
            sameCount++;
        }
    }
    
    min_count = min(min_count, count);

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
