#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
bool compare(string a, string b)
{

	if (a.size() == b.size()) return a < b;

	return a.size() < b.size();
}


int main()
{
	int N;
	cin >> N;

	vector<string> vec;
	vector<string> num;



	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		vec.push_back(s);

	}

	for (int i = 0; i < N; i++)
	{
		string s = vec[i];

		string ss;
		for (int j = 0; j < s.size(); j++)
		{
			//아스키코드 소문자 a : 97 ~ 122 숫자 0 : 48
			if (s[j] >= 48 && s[j] < 60)
			{
				ss += s[j];
			}
			else
			{
				if (ss.size() > 0)
				{
					while (ss.size() > 1 && ss[0] == '0')
					{
						ss.erase(ss.begin(), ss.begin() + 1);
					}

					num.push_back(ss);
				}
				ss.clear();
			}
		}
		if (ss.size() > 0)
		{
			while (ss.size() > 1 && ss[0] == '0')
			{
				ss.erase(ss.begin(), ss.begin() + 1);
			}

			num.push_back(ss);
		}
		ss.clear();
	}

	sort(num.begin(), num.end(), compare);


	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << endl;
	}
}