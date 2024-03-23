#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <math.h>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N;
vector<int> vec;
void Input()
{
    cin >> N;
}

void Init()
{
}

void Slove()
{

    string str = to_string(N);
    int size = str.size();
    int start = pow(10, size - 2);
    int sum = 0;
    for (int i = start; i < N; i++)
    {
        string s = to_string(i);
        sum = i;
        for (int j = 0; j < s.size(); j++)
        {
            sum += (s[j] - '0');
        }

        if(sum == N) vec.push_back(i);
    }

    sort(vec.begin(), vec.end());
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();
    if(vec.size() ==0) cout << 0 << endl;
    else cout << vec[0] << endl; 
}
