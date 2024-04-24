
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
#include <regex>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N, K;
vector<string> vec;
bool isAlphabet[26];
int max_count = 0;
void Input()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        vec.push_back(s.substr(4, s.length() - 8));
    }
}

void Init()
{
    isAlphabet[0] = true;
    isAlphabet[2] = true;
    isAlphabet[8] = true;
    isAlphabet[13] = true;
    isAlphabet[19] = true;

}

int Check()
{
    bool flag;
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        string str = vec[i];
        flag = true;
        for (int j = 0; j < str.length(); j++)
        {
            if (!isAlphabet[str[j] - 'a'])
            { 
                flag = false;
                break;
            }
        }

        if (flag) 
            count++;
    }

    return count;
}

void DFS(int _index, int _count)
{
    if (_count == K)
    {
        max_count = max(max_count, Check());
    }

    for (int i = _index; i < 26; i++)
    {
        if (isAlphabet[i]) continue;

        isAlphabet[i] = true;
        DFS(i, _count + 1);
        isAlphabet[i] = false;
    }
}

void Slove()
{
    if (K < 5)
    {
        cout << 0 << endl;
        return;
    }
    K = K - 5;
    DFS(0, 0);

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
