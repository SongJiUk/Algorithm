#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
#define MAX 100000
using namespace std;



vector<int> vec;
int DP[MAX];


int main(void)
{
    int N;
    

    cin >> N;
    for(int i =0; i<N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    if(N == 1) 
    {
        cout << vec[0] << endl;
        return 0;
    }
    

    DP[0] = vec[0];
    //DP[1] = DP[0] + vec[1];
    
    for(int i =1; i<N; i++)
    {
        DP[i] = max(DP[i-1]+vec[i], vec[i]);
    }

    int num = -1002;
    for(int i =0; i<N; i++)
    {
        num = max(num, DP[i]);
    }

    cout << num << endl;
}
