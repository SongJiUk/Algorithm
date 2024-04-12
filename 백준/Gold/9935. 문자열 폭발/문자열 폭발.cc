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

string s, word;
stack<char> stacks;
void Input()
{
    cin >> s;
    cin >> word;
}

void Init()
{
}

void Slove()
{
    for (int i = 0; i < s.length(); i++)
    {
        stacks.push(s[i]);


        if (s[i] == word[word.length() - 1] && stacks.size() >= word.length())
        {
            string str;
            for (int j = 0; j < word.length(); j++)
            {
                str += stacks.top();
                stacks.pop();
            }

            reverse(str.begin(), str.end());

            if (str != word)
            {
                for (int j = 0; j < str.length(); j++)
                {
                    stacks.push(str[j]);
                }
            }
        }
            
    }

    if (stacks.empty())
        cout << "FRULA" << endl;
    else
    {
        string str1;
        while (!stacks.empty())
        {
            char c = stacks.top();
            stacks.pop();
            str1 += c;
        }   

        reverse(str1.begin(), str1.end());
        cout << str1 << endl;
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
