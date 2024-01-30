#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> um;

    for(auto name : completion)
    {
        um[name]++;
    }

    for(auto name : participant)
    {
        um[name]--;
        if(um[name] < 0) answer = name;
    }

    
    return answer;
} 