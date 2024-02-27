#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
#define MAX 100000

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
queue<pair<int,int>> q;
int N, K;
bool visit_num[200001];
int BFS()
{
    while(!pq.empty())
    {
        int count = pq.top().first;
        int num = pq.top().second;

        pq.pop();
        if(num == K) return count;

        int telpo = num * 2;
        int walk_back = num - 1;
        int walk_front = num + 1;

        if(telpo <= MAX && !visit_num[telpo])
        {
            pq.push({count, telpo});
            visit_num[telpo] = true;
        }
        if(walk_back >= 0  && !visit_num[walk_back])
        {
            pq.push({count+1, walk_back});
            visit_num[walk_back] = true;
        }
        if(walk_front<=MAX && !visit_num[walk_front])
        {
            pq.push({count+1, walk_front});
            visit_num[walk_front] = true;
        }
    }

    return 0;
}

int main(void)
{
    
    cin >> N >> K;

    q.push({0, N});
    pq.push({0, N});


    if(N > K) cout << N-K << endl;
    else if(N == K) cout << 0 << endl;
    else cout << BFS() << endl;
    
}