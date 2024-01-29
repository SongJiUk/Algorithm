#include <iostream>
#include <queue>

using namespace std;

bool Compare(int a, int b)
{
    return a > b;
}

vector<int> coin;
int main(void)
{
    int n;
    cin >> n;

    for(int i =0; i<n; i++)
    {
        int a;
        cin >> a;
        coin.push_back(a);
    }

    sort(coin.begin(), coin.end(), Compare);

    int num =0, min =0;
    while(true)
    {
        num++;
        int a = num;
        for(int i =0; i<coin.size(); i++)
        {
            if(coin[i] > a) continue;
            else a -= coin[i];

            if(a == 0) break;   
        }

        if(a!=0)
        {
            min = num;
            break;
        }
    }

    cout << min;
}
