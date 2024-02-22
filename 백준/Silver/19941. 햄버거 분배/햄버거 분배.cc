#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> hambuger_que;
	queue<int> people_que;

	int count = 0;
	string s;
	cin >> s;

	for (int i = 0; i < N; i++)
	{
		if (s[i] == 'H')
		{
			//만약 K가
			hambuger_que.push(i);

			int num = hambuger_que.front();

			if (num + K <= i)
			{
				hambuger_que.pop();
			}

			if (people_que.size() > 0)
			{
				int ham_num = hambuger_que.front();
				int people_num = people_que.front();
				if (people_num + K >= ham_num)
				{
					hambuger_que.pop();
					people_que.pop();
					count++;
				}
			}

		}
		else if (s[i] == 'P')
		{

			people_que.push(i);

			int num = people_que.front();

			if (num + K <= i)
			{
				people_que.pop();
			}

			if (hambuger_que.size() > 0)
			{
				int ham_num = hambuger_que.front();
				int people_num = people_que.front();
				if (ham_num + K >= people_num)
				{
					hambuger_que.pop();
					people_que.pop();
					count++;
				}
			}



		}
	}

	cout << count << endl;
}