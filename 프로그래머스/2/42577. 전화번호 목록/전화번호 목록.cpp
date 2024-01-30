#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for(int i =0; i<phone_book.size()-1; i++)
    {
        string s = phone_book[i];

        if(phone_book[i+1].compare(0, s.size(), s) == 0)
        {
            answer = false;
            break;
        }
    }
    return answer;
}


//해시맵을 사용해서 한글자씩 받아와서 비교

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash_map;
    for(int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;

    for(int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && (phone_number != phone_book[i]))
                answer = false;
        }
    }
    return answer;
}
