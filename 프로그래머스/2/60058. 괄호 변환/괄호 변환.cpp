#include <string>
#include <vector>

using namespace std;

int balance(string p)
{
    int count = 0;
    for(int i = 0; i<p.size(); i++)
    {
        if(p[i] == '(') count+=1;
        else count-=1;

        if(count == 0) return i;
    }
    return -1;
}

bool checkProper(string p)
{
    int count = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') count += 1;
        else {
            if (count == 0) {
                return false;
            }
            count -= 1;
        }
    }
    return true;
}

string solution(string p) {
    string answer = p;
    
    if(p == "") return answer;
    int num = balance(p);
    string u = p.substr(0,num +1);
    string v = p.substr(num+1);

    
    if(checkProper(u))
    {
        answer = u + solution(v);
    }
    else
    {
        answer = '(';
        answer += solution(v);
        answer += ')';

        u = u.substr(1, u.size() -2);

         for(int i =0; i<u.size(); i++)
        {
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }

        answer += u;

    }
    
    
    return answer;
}