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

	//top - down
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

	//bottom - up
	//이렇게 게임 횟수를 넣어준다. - 3을 한번에 가져가는게 1을 세번 가져가는것과 같으니.
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		DP[i] = min(DP[i - 1] + 1, DP[i - 3] + 1);
	}
	

}
