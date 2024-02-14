#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second) return a.first<b.first;
    return a.second < b.second;
}


int main(void) {
    
    vector<pair<int,int>> vec;
    int N; 
    cin >> N;

    for(int i =0; i<N; i++)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }

    sort(vec.begin(), vec.end(), compare);


    int count = 1, standard = vec[0].second;
    for(int i =1; i<N; i++)
    {
        if(standard <= vec[i].first)
        {
            standard = vec[i].second;
            count++;
        }
    }

    cout << count<< endl;
}
