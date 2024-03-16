#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;


bool isCanNumber[1000];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int N;
    vector<pair<string, pair<int,int>>> vec;
    cin >> N;
    for(int i =0; i<N; i++)
    {
        string str;
        int s, b;
        cin >> str >> s >> b;
        vec.push_back({str, {s, b}}); 
    }
    for(int i = 0; i<1000; i++)
    {
        isCanNumber[i] = true;
    }

    for(int i = 123; i<1000; i++)
    {
        string str = to_string(i);
        if(str[0] == str[1] || str[0] == str[2] || str[1] == str[2]) isCanNumber[i] = false;
        if(str[0] == '0' || str[1] == '0' || str[2] == '0') isCanNumber[i] = false;
    }

    for(int i =0; i<vec.size(); i++)
    {
        string str1 = vec[i].first;
        int s1 = vec[i].second.first;
        int b1 = vec[i].second.second;

        for(int j =123; j<1000; j++)
        {
            string str2 = to_string(j);
            int s2 = 0;
            int b2 = 0;
            for(int a = 0; a<3; a++)
            {
                for(int b= 0 ; b< 3; b++)
                {
                    if(a == b && str1[a] == str2[b]) s2++;
                    if(a != b && str1[a] == str2[b]) b2++;

                }
            }
            if(s1 != s2 || b1 != b2) isCanNumber[j] = false;
        }
    }

    int count = 0;
    for(int i =123; i<1000; i++)
    {
        if(isCanNumber[i]) count++;
    }

    cout << count << endl;
}
