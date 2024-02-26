#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 1e9

using namespace std;

vector<int> vec;

bool compare(int a, int b)
{
    return a > b;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end(), compare);

    long long num = 0;
    for(int i =0; i<N; i++)
    {
        if(vec[i] - i > 0) num += vec[i] - i;
        else break;
    }


    cout << num << endl;
}