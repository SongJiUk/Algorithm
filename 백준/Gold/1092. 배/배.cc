#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    queue<int> crane;
    vector<int> crane_v;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        crane_v.push_back(x);
    }
    sort(crane_v.begin(), crane_v.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        crane.push(crane_v[i]);
    }

    int M;
    cin >> M;
    vector<int> box;
    priority_queue<int, vector<int>, less<int>> box_pq;
    queue<int> box_q;
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        box.push_back(x);
        box_pq.push(x);
    }

    // 이 박스를 그냥 pq에 넣어버리면 괜찮으려나?
    sort(box.begin(), box.end(), cmp);

    for(int i =0; i<M; i++)
    {
        box_q.push(box[i]);
    }
    int work_crane_count = 0;
    int count = 1;

    
    if (crane_v[0] < box[0])
    {
        cout << -1 << endl;
        return 0;
    }

    while (!box.empty())
    {
        if (work_crane_count == N)
        {
            count++;
            work_crane_count = 0;
        }

        int crane_power = crane.front();
        work_crane_count++;
        crane.pop();
        crane.push(crane_power);

        for (int i = 0; i < box.size(); i++)
        {
            int box_w = box[i];
            if (crane_power >= box_w)
            {
                box.erase(box.begin() + i);
                break;
            }
        }
    }

    cout << count << endl;
}
