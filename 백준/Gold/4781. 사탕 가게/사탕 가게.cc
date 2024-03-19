#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define MAX 1e9
typedef long long ll;
using namespace std;


int main()
{
	
	while (true)
	{
		int n,m;
		double d;
		cin >> n >> d;
		m = (int)(d * 100 +0.5);
		if (n == 0 && m == 0) break;
		vector<pair<int, int>> vec;
		int DP[10001] = { 0 };

		for (int i = 0; i < n; i++)
		{
			int c, p;
			double temp;
			cin >> c >> temp;
			p = (int)(temp * 100 + 0.5);
			vec.push_back({ p, c });
		}
		sort(vec.begin(), vec.end());

		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i - vec[j].first < 0) break;
				DP[i] = max(DP[i], DP[i - vec[j].first] + vec[j].second);
			}	
		}

		
		cout << DP[m] << endl;


	}

}