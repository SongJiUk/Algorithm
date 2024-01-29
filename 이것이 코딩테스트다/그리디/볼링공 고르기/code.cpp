#include <iostream>
#include <queue>

using namespace std;


vector<int> ball;
int main(void)
{
   int n,m;
   cin >> n >> m;

    int result = 0;
   for(int i = 0; i<5; i++)
   {
    int x;
    cin >> x;
    ball.push_back(x);
   }

   for(int i = 0; i<n; i++)
   {
    for(int j = i; j<=n-1; j++)
    {
        if(ball[i] != ball[j]) result++;
    }
   }

   cout << result;
}