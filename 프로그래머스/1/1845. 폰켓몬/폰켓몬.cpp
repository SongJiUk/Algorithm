#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    set<int> s;

    for(int i =0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    
    int n = nums.size() /2;

    if(s.size() > n) answer = n;
    else answer = s.size();  
    
    return answer;
}