#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
#define MAX 1e9

using namespace std;

vector<string> vec;

int main(void)
{
    int N;
    cin >> N;

    for(int i =0; i<N; i++)
    {
        string s;
        cin >> s;
        vec.push_back(s);
    }

    int count = 0;


    for(int i =0; i<N; i++)
    {
        stack<char> ab;
        string s = vec[i];

        if(s.size() % 2 == 0)
        {
            for(int j =0; j<s.size(); j++)
            {
                if(ab.size() == 0) ab.push(s[j]);
                else
                {
                    if(ab.top() != s[j]) ab.push(s[j]);
                    else
                    {
                        ab.pop();
                    }
                }
            }
            if(ab.size() == 0) count++;
        }
        
        
    }

    cout << count << endl;
}