
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
#include <regex>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int N, M;
vector<int> vec[32001];
vector<int> indegree(32001);
queue<int> q;
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        vec[A].push_back(B);

        indegree[B]++;
    }

}
void Init()
{
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0) q.push(i);
    }
}



void Slove()
{
   
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        cout << num << " ";

        for (int i = 0; i < vec[num].size(); i++)
        {
            indegree[vec[num][i]]--;

            if(indegree[vec[num][i]] == 0) q.push(vec[num][i]);
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
