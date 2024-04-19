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

string S, P;

void Input()
{
    cin >> S >> P;
}

void Init() 
{

}


void Slove()
{
    if(strstr(S.c_str(), P.c_str()) != NULL) cout << 1 << endl;
    else cout << 0 << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Init();
    Slove();
}
