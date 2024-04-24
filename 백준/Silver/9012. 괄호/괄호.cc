
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

int T;
vector<string> vec;
void Input()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string str;
        cin >> str;
        vec.push_back(str);
    }
    
}

void Init()
{
   

}



void Slove()
{
    for (int i = 0; i < vec.size(); i++)
    {
        stack<char> stacks;
        string s = vec[i];
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stacks.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!stacks.empty())
                {
                    if (stacks.top() == '(') stacks.pop();
                    else stacks.push(s[i]);
                }
                else
                {
                    stacks.push(s[i]);
                }
            }
        }

        if (stacks.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
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
