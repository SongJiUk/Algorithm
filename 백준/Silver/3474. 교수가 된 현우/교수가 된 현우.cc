
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

typedef long long ll;
#define endl '\n'
#define MAX 1e9
using namespace std;

int T;
void Input()
{
    cin >> T;
    for(int i =0; i<T; i++)
    {
        int N;
        cin >> N;

        int answer = 0;

        for(int j = 1; j <= 12; j++)
        {
            
            if((int)(N / pow(5,j)) == 0) break;
            answer += (N / pow(5, j));
        }

        cout << answer << endl;
    }
}

void Init()
{
    
}

void Slove()
{
    
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    Input();
    Init();
    Slove();
}
