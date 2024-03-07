#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <string>
typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;

//시계방향.
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int,pair<int,int>>> T_vec;
queue<int> q1;
queue<int> q2;

bool isFind[51][51];
int N, M, T;


void turn_left(vector<vector<int>>& _circle, int _num, int _count)
{
    for(int c = 0; c < _count; c++)
    {
        for(int i =1; i<= N; i++)
        {
            if(i % _num != 0) continue;

            for(int j = 1; j<= M; j++)
            {
                if(j == 1) q1.push(_circle[i][j]);
                else q2.push(_circle[i][j]);
            }

            for(int j =1; j<= M; j++)
            {
                if(j == M)
                {
                    _circle[i][j] = q1.front();
                    q1.pop();
                } 
                else
                {
                    _circle[i][j] = q2.front();
                    q2.pop();
                } 
            }
        }
    }
    
}


void turn_right(vector<vector<int>>& _circle, int _num, int _count)
{
    for(int c = 0; c < _count; c++)
    {
        for(int i =1; i<= N; i++)
        {
            if(i % _num != 0) continue;
            for(int j = 1; j<= M; j++)
            {
                if(j == M) q1.push(_circle[i][j]);
                else q2.push(_circle[i][j]);
            }

            for(int j =1; j<= M; j++)
            {
                if(j == 1)
                {
                    _circle[i][j] = q1.front();
                    q1.pop();
                } 
                else
                {
                    _circle[i][j] = q2.front();
                    q2.pop();
                } 
            }
        }
    }
    
}

void Find_Near_num(vector<vector<int>>& _circle)
{
    for(int i =1; i <= N; i++)
    {
        for(int j = 1; j<= M; j++)
        {
            isFind[i][j] = false;
        }
    }


    //근접찾기.
    bool isflag = false;
    for(int i = 1; i<= N; i++)
    {
        for(int j = 1; j<= M; j++)
        {
            if(_circle[i][j] == 0) continue;
            
            for(int k = 0; k < 4; k++)
            {
                int nx = dx[k] + i;
                int ny = dy[k] + j;

                if(nx == 0 || nx > N) continue;

                if(ny == 0) ny = M;
                else if(ny > M) ny = 1;

              
                if(_circle[i][j] == _circle[nx][ny]) 
                {
                    isflag = true;
                    isFind[i][j] = true;
                    break;
                }
                
            }
        }
    }

    //1. 있는경우에는 수를 지운다 0으로
    if(isflag)
    {
        for(int i =1; i<=N; i++)
        {
            for(int j = 1; j<=M; j++)
            {
                if(isFind[i][j])
                {
                    _circle[i][j] = 0;
                }
            }
        }
    }
    //2. 없는경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 뺴고, 작은수에는 1을 더한다.
    else
    {
        int number_count = 0;
        int sum = 0;
        for(int i =1; i<=N; i++)
        {
            for(int j =1; j<=M; j++)
            {
                if(_circle[i][j] > 0)
                {
                    sum += _circle[i][j];
                    number_count++;
                }
            }
        }

        double avg =(float)sum / (float)number_count;

        for(int i =1; i<=N; i++)
        {
            for(int j =1; j<= M; j++)
            {
                if(_circle[i][j] == 0) continue;
                
                if(_circle[i][j] > avg) _circle[i][j]--;
                else if(_circle[i][j] < avg) _circle[i][j]++;
            }
        }

    }

}

int sum_circle(vector<vector<int>>& _circle)
{
    int sum = 0;
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<= M; j++)
        {
            sum += _circle[i][j];
        }
    }
    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> N >> M >> T;
    vector<vector<int>> circle(N+1, vector<int>(M+1));

    for(int i =1; i<=N; i++)
    {
        for(int j =1; j<=M; j++)
        {
            cin >> circle[i][j];
        }
    }


    for(int i =0; i<T; i++)
    {
        // xi, di, ki주어짐
        //번호가 xi의 배수인 판을 di방향으로 회전(0 - 시계방향, 1 - 반시계), ki 칸 회전
        int x,d,k;
        cin >> x >> d >> k;
        T_vec.push_back({x,{d,k}});
    }
    


    for(int i =0; i<T; i++)
    {
        int x = T_vec[i].first;
        int d = T_vec[i].second.first;
        int k = T_vec[i].second.second;

        if(d == 0) turn_right(circle, x, k);
        else turn_left(circle, x, k);

        Find_Near_num(circle);
    }

    cout << sum_circle(circle) << endl;

}
