#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> number;
vector<int> vec;
int N;
int max_vaule  = INT_MIN;
int min_vaule  = INT_MAX;


void DFS(int start, int num)
{
    if(start == N)
    {
        max_vaule = max(max_vaule, num);
        min_vaule = min(min_vaule, num);
    }
    else
    {
        if(number[0] > 0) // +
        {
            number[0] -=1;
            DFS(start + 1, num + vec[start]);
            number[0] +=1;
        }
        
        if(number[1] > 0) // -
        {
            number[1] -=1;
            DFS(start +1 , num - vec[start]);
            number[1] +=1;
        }

        if(number[2] > 0 ) // *
        {
            number[2] -= 1;
            DFS(start +1 , num * vec[start]);
            number[2] += 1;
        }

        if(number[3] > 0) // /
        {
            number[3] -= 1;
            DFS(start+1, num / vec[start]);
            number[3] += 1;
        }
    }
}


int main() {

    cin >> N;
    
    for(int i =0; i<N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }


    for(int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        number.push_back(x);
    }

    DFS(1, vec[0]);


    cout << max_vaule << endl;
    cout << min_vaule << endl;
    return 0;
}