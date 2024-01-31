#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
int answer = 1;
    
    unordered_map<string, int> um;
    
    //의상의 개수를 체크(굳이 이름까지 알 필요는 없으니까)
    for (int i = 0; i < clothes.size(); i++)
    {
        um[clothes[i][1]]++;
    }
    
    for (auto a : um)
    {
        answer *= a.second + 1;
    }


    answer -= 1;
    return answer;    return answer;
}