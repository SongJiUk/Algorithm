#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec(21, 0);


int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M;
    cin >> M;
    
    int s = 0;

    for (int i = 0; i < M; i++)
    {

        string s;
        int x;
        cin >> s;
        if (!(s == "all" || s == "empty")) cin >> x;

        if (s == "add")
        {
            // add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
            vec[x] = x;
        }
        else if (s == "remove")
        {
            // remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
            vec[x] = 0;
        }
        else if (s == "check")
        {
            // check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
            if (vec[x] == x)
                cout << "1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (s == "toggle")
        {
            // toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
            if (vec[x] == x)
                vec[x] = 0;
            else
                vec[x] = x;
        }
        else if (s == "all")
        {

            // all: S를 {1, 2, ..., 20} 으로 바꾼다.
            for (int i = 1; i < vec.size(); i++)
            {
                vec[i] = i;
            }
        }
        else if (s == "empty")
        {
            // empty: S를 공집합으로 바꾼다.
            fill(vec.begin(), vec.end(), 0);
        }
    }
}



// 비트마스크를 이용해 푸는법

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec(21, 0);


int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M;
    cin >> M;
    
    int s = 0;
    int bit = 0;
    for (int i = 0; i < M; i++)
    {

        string s;
        int x;
        cin >> s;
        if (!(s == "all" || s == "empty")) cin >> x;

        if (s == "add")
        {
            // add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
            bit |= (1 << x);
        }
        else if (s == "remove")
        {
            // remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
            bit &= ~(1 << x);
        }
        else if (s == "check")
        {
            // check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
            if(bit & (1 << x))
                cout << 1 << '\n';
            else 
                cout << 0 << '\n';
        }
        else if (s == "toggle")
        {
            // toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)

            bit ^= (1 << x);
        }
        else if (s == "all")
        {

            // all: S를 {1, 2, ..., 20} 으로 바꾼다.
            bit = (1 << 21) -1;
        }
        else if (s == "empty")
        {
            // empty: S를 공집합으로 바꾼다.
            bit = 0;
        }
    }
}

