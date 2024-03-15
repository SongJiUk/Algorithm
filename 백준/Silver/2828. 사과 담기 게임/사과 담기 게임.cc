#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, J;
    cin >> N >> M;

    cin >> J;
    vector<int> vec;
    for (int i = 0; i < J; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    int count = 0;
    int start = 1;
    int end = M;

    for (int i = 0; i < vec.size(); i++)
    {
        int num = vec[i];

        if (start <= num && num <= end) continue;
        else if(start > num)
        {
            count += abs(num - start);
            start = num;
            end = num + (M -1);
        }
        else if(start < num)
        {
            count += num - end;
            start = num - (M -1);
            end = num;
        }
    }

    cout << count << endl;
}
