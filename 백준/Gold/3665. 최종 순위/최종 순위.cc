#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

bool ranks[501][501];
int indegree[501];

int main() {
    
    int tc;
    cin >> tc;


    //테스트 케이스 개수
    for(int t = 0; t < tc; t++)
    {


        fill(indegree, indegree+501, 0);
        for(int i =0; i< 501; i++)
        {
            fill(ranks[i], ranks[i] + 501, false);
        }
        int n;
        cin >> n;

        vector<int> vec;
        for(int i =0; i< n; i++)
        {


            int x;
            cin >> x;
            vec.push_back(x);

        }

        //위상정렬 세팅
        for(int i =0; i < vec.size(); i++)
        {
            for(int j = i +1; j < vec.size(); j++)
            {
                ranks[vec[i]][vec[j]] = true;
                indegree[vec[j]] += 1;
            }
        }

        //작년에 비해 바뀐 팀
        int m;
        cin >> m;

        for(int i =0; i<m; i++)
        {
            int a, b;
            cin >> a >> b;

            //이미 true이면 바꿔줌
            if(ranks[a][b])
            {
                ranks[a][b] = false;
                ranks[b][a] = true;
                indegree[b] -= 1;
                indegree[a] += 1;
            }
            else // 
            {
                ranks[a][b] = true;
                ranks[b][a] = false;
                indegree[b] += 1;
                indegree[a] -= 1;
            }
        }

        //위상정렬 준비
        queue<int> q;
        vector<int> result;
        
        
        //들어오는 값이 0인 수부터 하나씩 빼주기.
        for(int i =1; i<=n; i++)
        {   
            if(indegree[i] == 0) 
            {
                q.push(i);
            }
        }

        bool bNotSure = false;
        bool bImpossible = false;
        for(int i = 1; i <= n; i++)
        {
            
            if(q.empty())
            {
                bImpossible = true;
                break;
            }
            
            if(q.size() > 1) 
            {
                bNotSure = true;
                break;
            }

            int num = q.front();
            q.pop();
            result.push_back(num);

            for(int j = 1; j <= n; j++)
            {
                if(ranks[num][j])
                {
                    ranks[num][j] = false;
                    indegree[j] -= 1;


                    if(indegree[j] == 0) q.push(j);
                }

            }
        }

        
        if(bImpossible) cout << "IMPOSSIBLE" << endl;
        else if(bNotSure) cout << "?" << endl;
        else
        {
            for(int i = 0; i<result.size(); i++)
            {
                cout << result[i] << " ";
            }
            cout << endl;
        }


    }
    return 0;
}