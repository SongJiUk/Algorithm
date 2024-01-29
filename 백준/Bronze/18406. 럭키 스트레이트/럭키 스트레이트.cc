#include <iostream>
#include <queue>

using namespace std;



int main(void) {

int n;
cin >> n;

string snum = to_string(n);

int Lsum = 0, Rsum = 0;
for(int i =0; i<snum.length()/2; i++)
{
    Lsum += snum[i] - '0';
}

for(int i = snum.length()/2; i < snum.length(); i++)
{
    Rsum += snum[i] - '0';
}

if(Lsum == Rsum) cout << "LUCKY";
else cout << "READY";
}