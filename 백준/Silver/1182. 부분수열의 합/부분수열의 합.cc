#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
#define MAX 1e9
using namespace std;

int N, S;
int counts = 0;

vector<int> vec;
bool isVisit[21];


void DFS(int _index, int _sum)
{
    if(_index == N)
    {
        if(S == _sum)
        {
            counts++;
        }
        return;
    }

   DFS(_index +1, _sum + vec[_index]);

   DFS(_index +1, _sum);
    
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> N >> S;

    
    for(int i =0; i<N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    DFS(0, 0);

    if(S == 0) counts--;

    cout << counts << endl;
}
