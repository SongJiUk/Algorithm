#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 1e9

using namespace std;


vector<pair<int,int>> vec;
vector<int> now(302, 0);
int DP[302][302];
int N, M, K, T;



int DFS(int _array_Num, int _remain_f, int _prev_f)
{
    int start_num = vec[_array_Num].second;

    if(_array_Num == vec.size()) return 0;
    if(DP[_array_Num][_remain_f]) return DP[_array_Num][_remain_f];


    int cost = max(0, (T - start_num)); // T - 욱제의 친구들의 수 => 필요한 선영이의 친구들의 수
    int real_cost = (_prev_f >= cost) ? 0 : cost; //전에 들어가있던 선영이의 친구들의 수 >= 필요한 선영이의 친구들의수 ? 필요한 선영이의 친구 : 0 : 필요한 선영이의 친구들의 수

    int &ret = DP[_array_Num][_remain_f];

    if(_remain_f - real_cost >= 0) //남은 선영이의 친구의 수 - 필요한 선영이의 친구의 수가 0보다 크거나 같을경우(선영이의 친구를 더해서 파티를 이어나갈 수 있을경우)
    {
        //필요한 경우이니 값을 더해주거나, 그냥 넘어가거나. vec[_array_Num].first를 하는 이유는 시간을 저장해 놓았기 떄문.
        return ret = max(DFS(_array_Num + 1, _remain_f - real_cost, cost) + vec[_array_Num].first, DFS(_array_Num+1, _remain_f, 0));
    }
    else //남은 선영이의 친구의 수 - 필요한 선영이의 친구의 수가 0보다 작을경우(선영이의 친구들을 더해도 파티를 이어나갈 수 없을 경우)
    {
        return ret = DFS(_array_Num +1, _remain_f, 0);
    }
}

int main(void)
{
    
    cin >> N >> M >> K >> T;

    for(int i =0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        for(int j = a; j < b; j++)
        {
            now[j] = min(T, ++now[j]);
        }
    }

    int temp = now[1];
    int count = 1;

    for(int i = 2; i<= N; i++)
    {
        if(temp != now[i])
        {
            vec.push_back({count, temp});
            temp = now[i];
            count = 0;
        }
        count++;
    }
    vec.push_back({count, temp});

    cout << DFS(0, K, 0) << endl;

}