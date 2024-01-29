
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> vec;

int parent[100001];
int find_parent(int x)
{
    if(parent[x] == x) return x;

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

    int G, P;
    cin >> G;
    cin >> P;
    
    for(int i =0; i<P; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    for(int i =0; i<=G; i++)
    {
        parent[i] = i;
    }

    int result = 0;
    for(int i = 0; i<vec.size(); i++)
    {

        int root = find_parent(vec[i]);
        if(root == 0) break;

        union_parent(root, root-1);
        result+=1;
    }

    cout << result;
}  
