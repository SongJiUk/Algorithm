
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

string s;
stack<char> stacks;

void Input()
{
    
    cin >> s;
    
   
}

void Init()
{

}



void Slove()
{
    int temp = 1;
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            temp *= 2;
            stacks.push('(');
        }
        else if (s[i] == '[')
        {
            temp *= 3;
            stacks.push('[');
        }
        else if (s[i] == ')')
        {
            if (stacks.empty() || stacks.top() != '(')
            {
                cout << 0 << endl;
                return;
            }
            else if (s[i - 1] == '(')
            {
                sum += temp;
                temp /= 2;
                stacks.pop();
            }
            else
            {
                temp /= 2;
                stacks.pop();
            }
        }
        else if (s[i] == ']')
        {
            if (stacks.empty() || stacks.top() != '[')
            {
                cout << 0 << endl;
                return;
            }
            else if (s[i - 1] == '[')
            {
                sum += temp;
                temp /= 3;
                stacks.pop();
            }
            else
            {
                temp /= 3;
                stacks.pop();
            }
        }

    }

    if (!stacks.empty()) cout << 0 << endl;
    else cout << sum << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init(); 
    Slove();

}
