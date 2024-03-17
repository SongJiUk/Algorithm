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

queue<pair<string, int>> q;
priority_queue<int> pq;
map<pair<int, int>, bool> isVisit;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    // 16375, 1

    q.push({to_string(N), 0});

    while (!q.empty())
    {
        string snum = q.front().first;
        int count = q.front().second;
        
        isVisit[{count, stoi(snum)}] = true;

        if (count == K)
        {
            pq.push(stoi(snum));
            q.pop();
            continue;
        }

        for (int i = 0; i < snum.size() - 1; i++)
        {
            for (int j = i + 1; j < snum.size(); j++)
            {
                string s = snum;
                if(s[j] =='0' && i == 0) continue;
                
                swap(s[i], s[j]);

                if (!isVisit[{stoi(s), count}])
                {
                    isVisit[{stoi(s), count}] = true;
                    q.push({s, count + 1});
                }
            }
        }
        q.pop();
    }

    if(pq.empty()) cout << -1 << endl;
    else
    {
        cout << pq.top() << endl;
    }
}
