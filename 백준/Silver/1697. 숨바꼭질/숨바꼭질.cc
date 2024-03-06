#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 100000
using namespace std;

int N, K;
int min_count = MAX;

priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
bool isVisit[200001];
int BFS()
{
    while(!pq.empty())
    {
        int count = pq.top().first;
        int num = pq.top().second;
        pq.pop();

        if(num == K) return count;

        if(num * 2 <= MAX && !isVisit[num*2])
        {
            pq.push({count + 1, num * 2});
            isVisit[num*2] = true;
        }
        
        if(num -1 > 0 && !isVisit[num-1])
        {
            pq.push({count +1, num -1});
            isVisit[num -1] = true;
        }
        
        if(num + 1 <= MAX && !isVisit[num +1])
        {
            pq.push({count + 1, num +1});
            isVisit[num +1] = true;
        }
        

       
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> N >> K;

    pq.push({0, N});

    
    if(N > K) cout << N - K << endl;
    else if(N == K) cout << 0 << endl;
    else cout << BFS() << endl;


}
