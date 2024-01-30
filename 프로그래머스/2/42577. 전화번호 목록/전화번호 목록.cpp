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