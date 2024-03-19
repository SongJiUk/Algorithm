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
	int N, score, P;
	cin >> N >> score >> P;
	
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int s;
		cin >> s;
		vec.push_back(s);
	}

	int count = 0;
	int rank = 1;

	for (int i = 0; i < N; i++)
	{
		if (vec[i] > score) rank++;
		else if (vec[i] == score) rank = rank;
		else break;

		count++;
	}

	if (count == P) rank = -1;
	
	if (N == 0) rank = 1;
	
	cout << rank << endl;
}