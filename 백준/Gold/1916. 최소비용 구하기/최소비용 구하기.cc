
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>


typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N, M, start_con, end_con;

vector<pair<int, int>> vec[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool isVisit[1001];
void Input()
{
   
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({ b,c });
    }

    cin >> start_con >> end_con;
}

void Init()
{
    for (int i = 0; i < vec[start_con].size(); i++)
    {
        int dest = vec[start_con][i].first;
        int cost = vec[start_con][i].second;
        pq.push({ cost, dest });
    }
}



void Slove()
{
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int dest = pq.top().second;
        pq.pop();
        if (isVisit[dest]) continue;
        isVisit[dest] = true;

        if (dest == end_con)
        {
            cout << cost << endl;
            return;
        }

        for (int i = 0; i < vec[dest].size(); i++)
        {
            int d = vec[dest][i].first;
            int c = vec[dest][i].second;
            pq.push({ cost + c , d });
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init(); 
    Slove();

}
