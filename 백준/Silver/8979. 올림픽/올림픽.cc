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


int N, K, ranks = 0;
int Gold[1001];
int Silver[1001];
int Bronze[1001];
void Input()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int index;
        cin >> index;
        cin >> Gold[index] >> Silver[index] >> Bronze[index];
    }
}

void Init()
{

}

void Slove()
{
   for(int i =1; i<= N; i++)
   {
        if(Gold[i] > Gold[K])
        {
            ranks++;
        }
        else if(Gold[i] == Gold[K])
        {
            if(Silver[i] > Silver[K])
            {
                ranks++;
            }
            else if(Silver[i] == Silver[K])
            {
                if(Bronze[i] > Bronze[K])
                {
                    ranks++;
                }
            }
        }
   }

   cout << ranks + 1 << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();


}
