#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CountByRange(vector<string>& v, string leftvalue, string rightvalue)
{
    auto rightIndex = upper_bound(v.begin(), v.end(), rightvalue);
    auto leftIndex = lower_bound(v.begin(), v.end(), leftvalue);

    return rightIndex- leftIndex;
}

string replaceAll(string str, string from, string to)
{
    string res = str;
    int pos = 0;

    while((pos = res.find(from, pos)) != string::npos)
    {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }

    return res;
}



vector<string> arr[10001];
vector<string> reverse_words[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
     vector<int> answer;

    

    for(int i =0; i<words.size(); i++)
    {
        string word = words[i];
        arr[word.size()].push_back(word);

        reverse(word.begin(), word.end());
        reverse_words[word.size()].push_back(word);
    }
    //일단 접두사에 오도록 해보자.


    for(int i =0; i<10001; i++)
    {
        sort(arr[i].begin(), arr[i].end());
        sort(reverse_words[i].begin(), reverse_words[i].end());
    }

    for(int i =0; i<queries.size(); i++)
    {
        string q = queries[i];
        
        int res = 0;
        if(q[0] != '?')
        {
            //그대로 진행
            res = CountByRange(arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
        else
        {
            reverse(q.begin(), q.end());
            res = CountByRange(reverse_words[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));

        }
        answer.push_back(res);
    }

    return answer;
}