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

vector<int> vec;
int N;
void Input()
{
    cin >> N;
}

void Init()
{

}
void Slove()
{
    
    int start = 666;
    int count = 0;
    while(count < N)
    {
        string s = to_string(start);

        if(s.find("666") != string::npos)
        {
            vec.push_back(start);
            count++;
        }

        start++;
    }
   
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();

    cout << vec[N -1] << endl;
}
