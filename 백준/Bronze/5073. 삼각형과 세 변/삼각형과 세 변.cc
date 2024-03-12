#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

int main()
{
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		if (a == b && b == c)
		{
			cout << "Equilateral" << endl;
			continue;
		}

		int max_num = 0;

		max_num = max(a, max(b, c));

		if (a + b + c - max_num <= max_num)
		{
			cout << "Invalid" << endl;
			continue;
		}

		if (a == b || b == c || c == a)
		{
			cout << "Isosceles" << endl;
			continue;
		}

		if (a != b && b != c && c != a)
		{
			cout << "Scalene " << endl;
			continue;
		}

	}
}