#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;


int DP[1000];
int main()
{
	int N;
	cin >> N;

	DP[0] = N;

	int i = 0;
	while (true)
	{
		if (DP[i] == 0)
		{
			if (i % 2 == 0) cout << "CY" << endl;
			else cout << "SK" << endl;
			break;
		}
		if (DP[i] >= 3) DP[i + 1] = DP[i] - 3;
		else DP[i + 1] = DP[i] - 1;

		i++;
	}
}