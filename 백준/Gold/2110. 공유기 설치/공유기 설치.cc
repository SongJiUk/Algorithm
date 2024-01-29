#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

    int N, C;
    vector<int> vec;

int main(void) {

    cin >> N >> C;

    
    for(int i = 0; i< N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }


    
    sort(vec.begin(), vec.end());
    
    int start, end, mid, count, result;


    start = 1;
    end = vec[N-1] - vec[0];

    while(start <= end)
    {
        mid = (start +end) /2;
        count = 1;

        int st = vec[0];

        for(int i =0; i< N; i++)
        {
            if(vec[i] >= mid + st)
            {
                count++;
                st = vec[i];
            }
        }

        if(count >= C)
        {
            start = mid +1;
            result = mid;
        }
        else
        {
            end = mid -1;
        }
    }

    cout << result << endl;
}