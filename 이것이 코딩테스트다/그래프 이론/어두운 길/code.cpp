#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;


vector<int> parent;
vector<pair<int, pair<int,int>>> vec;

bool compare(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b)
{
    return a.first < b.first;
}

int find_parent(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}


void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {

    int n,m;
    int count = 0, Acount = 0;

    cin >> n >> m;

    for(int i =0; i<n; i++)
    {
        parent.push_back(i);
    }


    for(int i =0; i< m; i++)
    {
        int x,y,z;

        cin >> x >> y >> z;

        vec.push_back({z, {x, y}});

        Acount += z;

    }

    sort(vec.begin(), vec.end(), compare);


    for(int i =0; i<m; i++)
    {
        int cost = vec[i].first;
        int x = vec[i].second.first;
        int y = vec[i].second.second;

        if(find_parent(x) != find_parent(y))
        {
            union_parent(x, y);
            count += cost;
        }
    }


    cout << Acount - count << endl;
}
