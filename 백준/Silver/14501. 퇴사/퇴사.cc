#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int DP[16];
int T[16];
int P[16];

int main(void) {
    
    int N,max_value = 0;
    cin >> N;

    for(int i =0; i<N; i++)
    {
        int x,y;
        cin >> x >> y;

        T[i] = x;
        P[i] = y;        
    }


    for(int i =N-1; i>=0; i--)
    {

        if((T[i]+i) <= N)
        {
            DP[i] = max(P[i] + DP[T[i] +i], max_value);
            max_value = DP[i];
        }
        else
        {
            DP[i] = max_value;
        }
    }
    

    cout << max_value << endl;
}