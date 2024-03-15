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

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
queue<pair<int, pair<int,int>>> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    q.push({0, {0, 0}});
    //vector<vector<bool>> isVisit(a, vector<bool>(b, false)); 
    map<pair<int,int>, bool> isVisit;
    bool isFind = false;
    while (!q.empty())
    {
        int count = q.front().first;
        int numA = q.front().second.first;
        int numB = q.front().second.second;
        isVisit[{numA, numB}] = true;
        q.pop();

        if (numA == c && numB == d)
        {
            cout << count << endl;
            isFind = true;
            break;
        }

        if (numA == 0 && numB == 0)
        {
            q.push({count + 1, {numA + a, numB}});
            q.push({count + 1, {numA, numB + b}});
            continue;
        }


        //F(A)
        if(numA < a && !isVisit[{a, numB}])
        {
            isVisit[{a, numB}] = true;
            q.push({count +1, {a, numB}});
        }

        //F(B)
        if(numB < b && !isVisit[{numA, b}])
        {
            isVisit[{numA, b}] = true;
            q.push({count + 1,{numA, b}});
        }
        //E(A)
        if(numA != 0 && !isVisit[{0, numB}])
        {
            isVisit[{0, numB}]= true;
            q.push({count +1, {0, numB}});
        }

        //E(B)
        if(numB != 0 && !isVisit[{numA, 0}])
        {
            isVisit[{numA, 0}] = true;
            q.push({count +1, {numA, 0}});
        }

        int nA =0, nB = 0;
        //M(AB)
        nB = numB + numA;
        if(nB > b)
        {
            nA = nB - b;
            nB = b;
        }
        else nA = 0;

        if(numB != b && !isVisit[{nA, nB}])
        {
            isVisit[{nA, nB}] = true;
            q.push({count +1,{nA, nB}});
        }
        //M(BA)
        nA = numA + numB;
        if(nA > a)
        {
            nB = nA - a;
            nA = a;
        }
        else nB = 0;
        
        if(numA != a && !isVisit[{nA, nB}])
        {
            isVisit[{nA, nB}] = true;
            q.push({count +1, {nA, nB}});
        }
    }

    if(!isFind) cout << -1 << endl;
}
