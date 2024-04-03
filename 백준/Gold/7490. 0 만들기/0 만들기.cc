
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

bool cmp(string a, string b)
{
    for (int i = 0; i < a.size(); i++)
    {
        char c1 = a[i];
        char c2 = b[i];

        if (c1 == ' ' && c2 != ' ')
            return true;
        if (c1 != ' ' && c2 == ' ')
            return false;

        if (c1 == '+' && c2 != '+')
            return true;
        if (c1 != '+' && c2 == '+')
            return false;

        if (c1 == '-' && c2 != '-')
            return true;
        if (c1 != '-' && c2 == '-')
            return false;
    }
    return a < b;
}

int T;
int N;
vector<string> vec;
vector<string> answer;
queue<pair<int, int>> q;
void Slove();
// space > + > -
void DFS(int _start, int _count, string _s)
{
    if (_count == N)
    {
        vec.push_back(_s);
        return;
    }
    string s = _s;
    _s += "+" + to_string(_start + 1);
    DFS(_start + 1, _count + 1, _s);
    _s = s;
    _s += "-" + to_string(_start + 1);
    DFS(_start + 1, _count + 1, _s);
    _s = s;
    _s += " " + to_string(_start + 1);
    DFS(_start + 1, _count + 1, _s);
}

void Input()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        DFS(1, 1, "1");

        Slove();
        vec.clear();
        answer.clear();

        cout << endl;
    }
}

void Init()
{
}

void Slove()
{

    for (int i = 0; i < vec.size(); i++)
    {
        string s = vec[i];
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (s[j] == ' ')
            {
                q.push({2, j});
            }

            else if (s[j] == '+')
            {
                q.push({1, j});
            }

            else if (s[j] == '-')
            {
                q.push({0, j});
            }
        }

        string str1 = "1";
        // 여기서 해결
        while (!q.empty())
        {

            int num = q.front().first;
            int location = q.front().second;

            q.pop();

            if (num == 0)
            {
                str1 += '-';
                str1 += s[location + 1];
            }
            else if (num == 1)
            {
                str1 += '+';
                str1 += s[location + 1];
            }
            else if (num == 2)
            {
                str1 += s[location + 1];
            }
        }

        int count = 0;
        int sum = 0;

        for (int j = str1.size() - 1; j >= 0; j--)
        {
            count++;

            if (j == 0)
            {
                sum += stoi(str1.substr(0, count));
            }

            if (str1[j] == '+')
            {
                sum += stoi(str1.substr(j + 1, count - 1));
                count = 0;
            }
            else if (str1[j] == '-')
            {
                sum -= stoi(str1.substr(j + 1, count - 1));
                count = 0;
            }
        }

        if (sum == 0)
            answer.push_back(s);
    }

    sort(answer.begin(), answer.end(), cmp);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
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
