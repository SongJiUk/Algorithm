#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i =0; i<completion.size(); i++)
    {
        if(participant[i] != completion[i])
        {
            return participant[i];
        }
    } 
    return participant[participant.size() -1 ];
} 

//해시맵 사용
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> um;

    for(const auto name : completion)
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
