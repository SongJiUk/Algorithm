
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

int N;
vector<pair<string, int>> vec;
vector<pair<string, int>> vec_copy;
vector<int> v(20001);
vector<string> str;
int max_num = 0;

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        vec.push_back({s, i});
        vec_copy.push_back({s, i});
        str.push_back(s);
    }
}

void Init()
{
    sort(vec.begin(), vec.end());
}

int Check(string _str1, string _str2)
{
    int count = 0;
    int min_num = min(_str1.length(), _str2.length());
    for (int i = 0; i < min_num; i++)
    {
        if (_str1[i] != _str2[i])
            break;
        else
            count++;
    }

    return count;
}

void Slove()
{
    for (int i = 0; i < N - 1; i++)
    {
        int tmp = Check(vec[i].first, vec[i + 1].first);
        max_num = max(max_num, tmp);

        v[vec[i].second] = max(v[vec[i].second], tmp);
        v[vec[i + 1].second] = max(v[vec[i + 1].second], tmp);
    }

    int first = 0;
    string str1;
    for (int i = 0; i < v.size(); i++)
    {
        if (first == 0)
        {
            if (v[i] == max_num)
            {
                cout << vec_copy[i].first << endl;
                first++;
                str1 = vec_copy[i].first.substr(0,max_num);
            }
        }
        else
        {
            string str2 = vec_copy[i].first.substr(0, max_num);
            if(v[i] == max_num && str1 == str2)
            {
                cout << vec_copy[i].first << endl;
                break;
            }
        }
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
