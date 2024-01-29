#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 1e9;
bool isDist[8];
vector<int> v;
bool compare(int a, int b)
{
    return a > b;
}

void Check(vector<int> _weak, vector<int> _dist, int _n)
{
    for(int i =0; i<_weak.size(); i++)
    {
        int weak_index = 0 ;
        bool isAllclear = false;
        int count = 0;

        for(int j = 0; j<v.size(); j++)
        {
            if(j +1 > answer) break;
            if(isAllclear) break;

            int num = _weak[weak_index] + _dist[v[j]];

            while(num >= _weak[weak_index])
            {
                weak_index++;
                if(weak_index == _weak.size())
                {
                    count = j+1;    
                    isAllclear = true;
                    break;
                }
            }
        }

        if(isAllclear) answer = min(answer, count);

        //마지막에 순서 바꿔주기. 
        int temp = _weak[0];
        for(int j =1; j<_weak.size(); j++) _weak[j-1] = _weak[j];

        _weak[_weak.size()-1] = temp + _n;
    }
}

void DFS(int _count, vector<int> _weak, vector<int> _dist, int _n)
{
    if(_count == _dist.size())
    {
        //4개일때
        Check(_weak, _dist, _n);
    }
    else
    {
        //순열로. 맨 처음은 4321
        for(int i =0; i<_dist.size(); i++)
        {
            if(isDist[i]) continue;
            isDist[i] = true;
            v.push_back(i);
            DFS(_count+1, _weak, _dist , _n);
            isDist[i] = false;
            v.pop_back();
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    answer = 1e9;

    sort(dist.begin(), dist.end(), compare);
    
    vector<int> temp = weak;
    //한방에 되는경우
    for(int i =0; i<temp.size(); i++)
    {
        int num = temp[0] + dist[0];
        if(num >= temp[temp.size() -1]) return 1;


        int value = temp[0];
        for(int j =1; j<temp.size(); j++) temp[j-1] = temp[j];

        temp[temp.size() -1] = value + n;
    }

    //한번 이상인경우 
    DFS(0, weak, dist, n);

    if(answer == 1e9) return -1;
    return answer;
}
