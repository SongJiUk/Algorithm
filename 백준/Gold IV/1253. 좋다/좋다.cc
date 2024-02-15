#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;\

int main(void)
{
    vector<int> vec;
    int goodNum = 0;

    int N;
    cin >> N;


    for(int i =0; i<N; i++)
    {
        int x;
        cin >> x;

        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());

    
    for(int i =0; i < N; i++)
    {
        int left = 0;
        int right = N-1;

        while(left<right)
        {
            if(left == i)
            {
                left++;
                continue;
            }
            
            if(right == i)
            {
                right--;
                continue;
            }

            if(vec[i] < vec[left] + vec[right]) right--;
            else if(vec[i] > vec[left] + vec[right]) left++;
            else { goodNum++; break;}
        }
    }
  
    cout << goodNum << endl;
}
