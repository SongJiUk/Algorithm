#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

bool bDP[2500][2500];
int DP[2500];
int main()
{
	string s;

	cin >> s;

	int size = s.length();
	//bDP[i][j] = i번째부터 j번째까지
	//bDP[0][0] = 0번째부터 0번째까지 팰린드롬이면 true
	for (int i = 0; i < size; i++)
	{
		bDP[i][i] = true;
	}

	for (int i = 0; i < size - 1; i++)
	{
		if (s[i] == s[i + 1]) bDP[i][i + 1] = true;
	}

	for (int k = 3; k <= size; k++)
	{
		for (int i = 0; i <= size - k; i++)
		{
			int j = i + k  - 1;

			if (s[i] == s[j] && bDP[i + 1][j - 1])
			{
				bDP[i][j] = true;
			}
		}
	}


	//여기서 DP는 i번째 문자열까지의 최솟값.

	DP[0] = 0;
	DP[1] = 1;

	for (int k = 2; k <= size; k++)
	{
		for(int i = 1; i<= k; i++)
		{
			//같아야 +1
			if (bDP[i-1][k - 1])
			{
				if (DP[k] == 0 || (DP[k] > DP[i - 1] + 1))
				{
					DP[k] = DP[i - 1] + 1;
				}
			}
		}
	}
	
	cout << DP[size] << endl;
}