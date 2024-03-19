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
	int N;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += vec[j];
		}
	}

	cout << sum << endl;
}