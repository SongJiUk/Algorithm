#include <iostream>
#include <queue>
#include <set>



using namespace std;

//union_find
int parent[501];
vector<pair<int,int> > vec;
set<int> s;
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

    int n, m;

    cin >> n >> m;
 for(int i = 1; i<=n; i++)
    {
        parent[i] = i;
    }


    for(int i =1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            int a;
            cin >> a;

            if(a == 1) union_parent(i,j);
        }
    }



//둘중 하나 하면 된다.

    vector<int> plan;
    //여행 게획 입력받아야됨
    for(int i = 0; i<m; i++)
    {
        int x;
        cin >> x;
        plan.push_back(x);
    }

    //루트가 동일한지 확인해야됌
    for(int i =0; i<plan.size(); i++)
    {
        s.insert(plan[i]);
    }

    if(s.size() > 1 ) cout << "No";
    else cout << "Yes";


     bool result = true;
    // 여행 계획에 속하는 모든 노드의 루트가 동일한지 확인
    for (int i = 0; i < m - 1; i++) {
        if (find_parent(plan[i]) != find_parent(plan[i + 1])) {
            result = false;
        }
    }

    // 여행 계획에 속하는 모든 노드가 서로 연결되어 있는지(루트가 동일한지) 확인
    if (result) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
