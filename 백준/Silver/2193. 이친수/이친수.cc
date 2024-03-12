#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define MAX 1e9
typedef long long ll;
using namespace std;

ll DP[91];
int main()
{
	int N;
	cin >> N;


	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N] << endl;
}