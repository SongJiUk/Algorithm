#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b)
{
    if(a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}



vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<int, float>> vec;

    int Count = 1;
    int length = stages.size();
    for(int i = 1; i<=N; i++)
    {
    int Count = count(stages.begin(), stages.end(),i);

    float fail = 0;
    if(length >= 1) fail = (float)Count / length;


    vec.push_back({i, fail});

    length -= Count;
}

sort(vec.begin(), vec.end(), compare);

for(int i =0; i < N; i++)
{
    answer.push_back(vec[i].first);
}
    return answer;
}