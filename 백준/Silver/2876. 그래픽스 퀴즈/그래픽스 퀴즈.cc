#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map> 
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long	
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000
#define endl '\n'
#define pil pair<int,int>

using namespace std;

int N;
int information[100003][2];
int cache[100003][8];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> information[i][0] >> information[i][1];
	}
}

int path(int seat, int grade) {
	if (seat > N) return 0;
	if (information[seat][0] != grade && information[seat][1] != grade) return 0;
	int& ret = cache[seat][grade];
	if (ret != -1) return ret;
	ret = 1;
	return ret += path(seat + 1, grade);
}

void solution() {
	memset(cache, -1, sizeof(cache));
	int student = 0, answerGrade = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			int temp = path(i, information[i][j]);
			if (student < temp) {
				student = temp;
				answerGrade = information[i][j];
			}
			else if (student == temp) answerGrade = min(answerGrade, information[i][j]);
		}
	}
	cout << student << " " << answerGrade << endl;
}

int main() {
	fastio;
	input();
	solution();
	 
	return 0;
}