#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define MAX 1e9
typedef long long ll;
using namespace std;

ll DP[1000001];
int main()
{
	int N;
	cin >> N;

	DP[0] = 1;
	DP[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		DP[i] = (DP[i - 2] + DP[i - 1]) % 15746;
	}
	
	cout << DP[N];
}