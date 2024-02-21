#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> vec;

int main()
{
	int N, M, L, K;
	int maxNum = 0;
	int num = 0;
	cin >> N >> M >> L >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;

		vec.push_back({ x,y });
	}


	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int x = vec[i].first;
			int y = vec[j].second;
			num = 0;

			for (int c = 0; c < K; c++)
			{	
				if (x <= vec[c].first && x + L >= vec[c].first && y <= vec[c].second && y + L >= vec[c].second)
				{
					num++;
				}
			}

			maxNum = max(maxNum, num);
		}

		
	}

	cout << K - maxNum << endl;
}