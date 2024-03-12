#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define MAX 1e9
typedef long long ll;
using namespace std;


priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
int DP[3000001];

int main()
{

	int N;
	cin >> N;

	

	for (int i = 0; i <= 1000001; i++)
	{
		DP[i] = MAX;
	}


	DP[N] = 0;
	for (int i = N; i > 0; i--)
	{
		if (i % 3 == 0)
		{
			int div3 = i / 3;
			DP[i / 3] = min(DP[i] + 1, DP[i / 3]);
		}

		if (i % 2 == 0)
		{
			int div2 = i / 2;
			DP[i / 2] = min(DP[i] + 1, DP[i / 2]);
		}

		DP[i - 1] = min(DP[i-1], DP[i] + 1);
	}

	cout << DP[1] << endl;
}