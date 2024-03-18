#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

typedef struct state
{
    int total_turn = -1;
    int turn = 0;
} State;

int N;
string start, goal;
State DP[10000][10];

int turn(int _index, int _turnleft)
{
    if (N == _index)
        return 0;

    int num = start[_index] - '0' + _turnleft;

    num %= 10;

    if (DP[_index][num].total_turn != -1)
        return DP[_index][num].total_turn;

    // 오른쪽 회전
    int right = 0;
    int dest_num = goal[_index] - '0';
    if (num > dest_num)
    {
        right = num - dest_num;
    }
    else
    {
        right = num + 10 - dest_num;
    }

    // 왼쪽 회전
    int left = 0;
    if (num > dest_num)
    {
        left = dest_num + 10 - num;
    }
    else
    {
        left = dest_num - num;
    }

    int left_num = turn(_index + 1, (_turnleft + left) % 10) + left;
    int right_num = turn(_index + 1, _turnleft) + right;

    if (left_num < right_num)
    {
        DP[_index][num].total_turn = left_num;
        DP[_index][num].turn = left;
    }
    else
    {
        DP[_index][num].total_turn = right_num;
        DP[_index][num].turn = -right;
    }

    return DP[_index][num].total_turn;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> start;
    cin >> goal;

    
    cout << turn(0, 0) << endl;

    int index = 0, num = start[0] - '0', total_left = 0;

    while(true)
    {
        cout << index + 1 << " " << DP[index][num].turn << endl;

        //왼쪽 이동
        if(DP[index][num].turn > 0)
        {
            total_left += DP[index][num].turn;
            total_left %= 10;
        }

        index++;
        if(index == N) break;

        num = (start[index] -'0' + total_left) % 10;
     }

}
