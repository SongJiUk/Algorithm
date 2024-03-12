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
	cin.ignore();

	for (int i = 1; i <= N; i++)
	{
		string s;
		getline(cin, s);
		cin.clear();
		cout << i << ". " << s << endl;
	}


}