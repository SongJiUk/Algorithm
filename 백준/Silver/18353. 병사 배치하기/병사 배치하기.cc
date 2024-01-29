#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    vector<int> Sold;
    vector<int> DP(2001, 1);


    int N;
    cin >> N;
    
    for(int i = 0; i< N; i++)
    {
        int x;
        cin >> x;
        Sold.push_back(x);
    }


    reverse(Sold.begin(), Sold.end());
    for(int i = 1; i<N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(Sold[i] > Sold[j]) DP[i] = max(DP[i], DP[j]+1);
        }
        
    }


    int count = 0;
    for(int i =0; i<N; i++)
    {
        count = max(count, DP[i]);
    }

    cout << N - count << endl;
    return 0;
}