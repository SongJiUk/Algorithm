#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
#define MAX 200001
using namespace std;

bool isVisit[MAX];

int N;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first) return a.second < b.second;

    return a.first < b.first;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i =0; i<N; i++)
    {
        int a,b;
        cin >> a >> b;
        vec.push_back({a,b});
    }

    sort(vec.begin(), vec.end(), compare);


    
    pq.push(vec[0].second);

    for(int i =1; i<N; i++)
    {
        pq.push(vec[i].second);

        int num = pq.top();

        if(vec[i].first >= num) pq.pop();
    }

    cout << pq.size() << endl;
}
