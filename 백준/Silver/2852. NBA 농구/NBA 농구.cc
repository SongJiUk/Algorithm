
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

vector<pair<int, string>> vec;
int N;
int score[3];
int total[3];
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        vec.push_back({x, s});
    }
}

void Init()
{
}

void Slove()
{

    int before_s = 0;

    for (int i = 0; i < N; i++)
    {
        int num = vec[i].first;
        string s = vec[i].second;

        int minute = stoi(s.substr(0, 2));
        int second = stoi(s.substr(3, 2));

        if (score[1] > score[2])
        {
            total[1] += (minute * 60) + second - before_s;
        }
        else if (score[1] < score[2])
        {
            total[2] += (minute * 60) + second - before_s;
        }

        if (num == 1)
            score[1]++;
        else
            score[2]++;
        before_s = (minute * 60) + second;
    }
    if (score[1] > score[2])
        total[1] += (48 * 60) - before_s;
    else if (score[1] < score[2])
        total[2] += (48 * 60) - before_s;

    for (int i = 1; i <= 2; i++)
    {
        string str1 = to_string(total[i] / 60);
        string str2 = to_string(total[i] % 60);
        if (str1.size() == 1)
            str1 = '0' + str1;
        if (str2.size() == 1)
            str2 = '0' + str2;

        cout << str1 << ":" << str2 << endl;
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
