
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

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;
int T, N;

multimap<string, string> mm;
multimap<string, int> mm2;
void Slove();

void Input()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        for (int j= 0; j < N; j++)
        {
            string str1, str2;
            cin >> str1 >> str2;
            mm.insert({str2, str1});
        }
        
        Slove();
        mm.clear();
        mm2.clear();
    }
}

void Init()
{
}

void Slove()
{
    
    for (auto a : mm)
    {
        string s = a.first;
        auto it = mm2.find(s);
        
        
        if (it == mm2.end()) mm2.insert({ s, 2 });
        else
        {
            it->second = it->second +1;
        }
    }

    int sum = 1;
    for (auto a : mm2)
    {
        sum = sum * a.second;
    }

    cout << sum -1 << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    //Slove();

}
