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

long long DP[90];
//1번 방법
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K;
    cin >> K;

    //자리수의 시작 지점을 저장.
    DP[0] = 1;
    DP[1] = 1;

    for(int i =2; i<=90; i++)
    {
        DP[i] = DP[i-1] + DP[i-2];
    }

    bool isUseDP = false;
    for(int i = 90; i >0; i--)
    {
        if(DP[i] <= K) isUseDP = true;
        
        if(isUseDP)
        {
            if(DP[i] <= K)
            {
                cout << "1";
                K -= DP[i];
            }
            else cout << "0";
        }
    }
    cout << endl;
}   

//2번방법

long long DP[90];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K;
    cin >> K;

    //자리수의 시작 지점을 저장.
    DP[1] = 1;
    DP[2] = 2;

    for(int i =3; i<=90; i++)
    {
        DP[i] = DP[i-1] + DP[i-2];
    }

    int length = 0;
    for(int i = 1; i<=90; i++)
    {
        if(DP[i] > K)
        {
            length = i - 1;
            break;
        }
    }

    while(length >0)
    {
        if(DP[length] <= K)
        {
            cout << 1;
            K -= DP[length];
        }
        else cout << 0;

        length--;
    }
    cout << endl;
}   
