#include <iostream>
using namespace std;
int n, answer = 100000, cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    if (!(n % 5))
    {
        answer = n / 5;
    }
    else
    {
        while (n > 0)
        {
            if (!(n % 2))
            {
                answer = n / 2 + cnt;
            }

            ++cnt;
            n -= 5;
        }
    }

    cout << (answer == 100000 ? -1 : answer);
    return 0;
}