#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <string>

#define endl '\n'
#define MAX 1e9
using namespace std;

int max_sum = 0;
int N;

int DP[1001];
vector<int> vec(1001);
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    for(int i =1; i<=N; i++)
    {
        int x;
        cin >> x;
        vec[i] = x;
    }

    DP[1] = vec[1];

    for(int i =1; i<N; i++)
    {
        for(int j = i +1; j <= N; j++)
        {
            if(vec[i] < vec[j])
            {
                DP[j] = max(DP[i] + vec[j], DP[j]);
            }
            else DP[j] = max(DP[j], vec[j]);
        }
    }   

    for(int i = 1; i<=N; i++)
    {
        max_sum = max(max_sum, DP[i]);
    }

    if(max_sum == 0) cout << DP[1] << endl;
    else cout << max_sum << endl;
}   
