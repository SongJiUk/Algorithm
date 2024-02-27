#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
#define MAX 9
using namespace std;



vector<int> vec;

vector<int> v;

bool isVisit[MAX];
bool flag = false;
void DFS(int _count, int _sum)
{
    if(_count == 7) 
    {
        if(_sum == 100) 
        {
                for(int i =0; i< MAX; i++)
                {
                    if(isVisit[i]) v.push_back(vec[i]);
                }
            
            
    sort(v.begin(), v.end());


    for(int i =0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
            
            exit(0);
        }
    }
    else
    {
        for(int i =0; i<MAX; i++)
        {
            if(isVisit[i]) continue;
            
            _sum += vec[i];
            isVisit[i] = true;
            _count++;

            DFS(_count, _sum);
            
            _sum -= vec[i];
            isVisit[i] = false;
            _count--;
            
        }
    }
}


int main(void)
{
    for(int i =0; i<MAX; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }


    DFS(0, 0);

}


//exit(0)을 사용하지 않은 코드
//이건 훨씬 많이 돌아서 위에가 성능에선 좋을지도?
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
#define MAX 9
using namespace std;



vector<int> vec;

vector<int> v;

bool isVisit[MAX];
bool flag = false;
void DFS(int _count, int _sum)
{
    if(_count == 7) 
    {
        if(_sum == 100) 
        {
            if(!flag)
            {
                flag = true;
                for(int i =0; i< MAX; i++)
                {
                    if(isVisit[i]) v.push_back(vec[i]);
                }
            }
            
            return;
        }
    }
    else
    {
        for(int i =0; i<MAX; i++)
        {
            if(isVisit[i]) continue;
            
            _sum += vec[i];
            isVisit[i] = true;
            _count++;

            DFS(_count, _sum);
            
            _sum -= vec[i];
            isVisit[i] = false;
            _count--;
            
        }
    }
}


int main(void)
{
    for(int i =0; i<MAX; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }


    DFS(0, 0);

    sort(v.begin(), v.end());


    for(int i =0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

