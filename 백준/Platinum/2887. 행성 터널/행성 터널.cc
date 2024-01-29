#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 1e9
using namespace std;

vector<pair<int,int>> x;
vector<pair<int,int>> y;
vector<pair<int,int>> z;

int parent[100001];
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


int main() {
   
   int N;
   cin >> N;

   for(int i = 1; i<=N; i++)
   {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
   }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
   
  
    vector<pair<int, pair<int,int>>> vec;

   for(int i = 1; i<N; i++)
   {    
        vec.push_back({abs(x[i].first - x[i-1].first),{x[i].second, x[i-1].second}});
        vec.push_back({abs(y[i].first - y[i-1].first),{y[i].second, y[i-1].second}});
        vec.push_back({abs(z[i].first - z[i-1].first),{z[i].second, z[i-1].second}});
   }

    sort(vec.begin(), vec.end(), compare);


    for(int i = 1; i<=N; i++)
    {
        parent[i] =i;
    }

    int result = 0;

    for(int i = 0; i<vec.size(); i++)
    {
        int x = vec[i].second.first;
        int y = vec[i].second.second;

        if(find_parent(x) != find_parent(y))
        {
            union_parent(x, y);
            result += vec[i].first;
        }
    }

    cout << result << endl;

    return 0;
}