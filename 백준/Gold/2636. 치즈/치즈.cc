#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define MAX 1e9
typedef long long ll;
using namespace std;

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q1;
int maps[100][100];
bool isVisit[100][100];
int N, M, Cheese = 0, times = 0, result = 0;

void ResetBool()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			isVisit[i][j] = false;
		}
	}
}

bool BFS()
{
	int count = 0;
	isVisit[0][0] = true;
	times++;
	queue < pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && !isVisit[nx][ny])
			{
				if (maps[nx][ny] == 0) q.push({ nx, ny });
				else
				{
					maps[nx][ny] = 0;
					count++;
				}
				isVisit[nx][ny] = true;
			}
		}
	}


	if (count == 0)
	{
		cout << --times << endl;
		cout << result << endl;
		return true;
	}
	else
	{
		result = count;
		return false;
	}
}

int main()
{	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
		}
	}
	
	while (true)
	{
		if (BFS()) break;
		ResetBool();
	}
	
}