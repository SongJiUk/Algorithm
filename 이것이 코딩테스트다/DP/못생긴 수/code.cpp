#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int DP[1000];

int main() {
    DP[0] = 1;

    int N;
    cin >> N;
    int mul2 =0, mul3 =0, mul5= 0;
    int ugly2 = 2, ugly3 = 3, ugly5 =5;
    for(int i =1; i<N; i++)
    {
        DP[i] = min(ugly2, min(ugly3, ugly5));
        if(DP[i] == ugly2)
        {
            mul2++;
            ugly2 = DP[mul2] *2;
        }

        if(DP[i] == ugly3)
        {
            mul3++;
            ugly3 = DP[mul3] * 3;

        }

        if(DP[i] == ugly5)
        {
            mul5++;
            ugly5 = DP[mul5] * 5;

        }
    }

    
    return 0;
}
