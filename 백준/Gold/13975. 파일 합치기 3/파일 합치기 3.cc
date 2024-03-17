#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;




int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int i =0; i<T; i++)
    {
        int K;
        cin >> K;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int j = 0; j<K; j++)
        {  
            int x;
            cin >> x;
            pq.push(x);
        }
        vector<ll> vec;
        while(!pq.empty())
        {
            ll num1 = pq.top();
            pq.pop();
            ll num2 = pq.top();
            pq.pop();

            ll sum = num1 + num2;
            vec.push_back(sum);
            if(!pq.empty()) pq.push(sum);
        }

        ll sum = 0;
        for(int j = 0; j< vec.size(); j++)
        {
            sum += vec[j];
        }

        cout << sum << endl;
    }

}
