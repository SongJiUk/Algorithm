
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>

typedef long long ll;

#define endl '\n'
#define MAX 1e9
using namespace std;
pair<int, int> dxy[5] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
int R, C, M;
int Start = 0;
int counts = 0;

class Shark
{
public:
    int r, c, s, d, z;
    bool isDelete;
    Shark(int _r, int _c, int _s, int _d, int _z, int _isDelete) : r(_r), c(_c), s(_s), d(_d), z(_z), isDelete(_isDelete)
    {
    }
};
vector<Shark> vec;
map<pair<int, int>, Shark> maps;
unordered_map<int, Shark> um;


int cmp(Shark a, Shark b)
{
    return a.r < b.r;
}
void Input()
{
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        vec.push_back(Shark(r, c, s, d, z, false));
    }
}

void Init()
{
}

void Slove()
{
    if (M == 0)
        return;

    while (Start < C)
    {
        // 낚시왕 이동
        Start++;
        // 같은 열에 있는 상어중 가장 땅에 가까운 상어 획득
        int near_shark_num = 0;
        int near_shark_r = MAX;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].c == Start && !vec[i].isDelete)
            {
                if (vec[i].r < near_shark_r)
                {
                    near_shark_r = vec[i].r;
                    near_shark_num = i;
                }
            }
        }


        if (near_shark_r != MAX)
        {
            counts += vec[near_shark_num].z;
            vec[near_shark_num].isDelete = true;
        }

        if (vec.size() == 0)
            break;
        // 상어들 이동. //d - 1(위) 2(아래) 3(오른쪽) 4(왼쪽) 여기서 0에 닿거나, C에 닿으면 방향 변환
        for (int i = 0; i < vec.size(); i++)
        {
            int r = vec[i].r;
            int c = vec[i].c;
            int s = vec[i].s;
            int d = vec[i].d;

            if (d == 1 || d == 2)
                s = s % ((R - 1) * 2);
            else if (d == 3 || d == 4)
                s = s % ((C - 1) * 2);

            for (int j = 0; j < s; j++)
            {
                if (r == 1 && d == 1)
                    d = 2;
                else if (r == R && d == 2)
                    d = 1;
                else if (c == 1 && d == 4)
                    d = 3;
                else if (c == C && d == 3)
                    d = 4;

                r += dxy[d].first;
                c += dxy[d].second;
            }

            vec[i].r = r;
            vec[i].c = c;
            vec[i].d = d;
        }

        
        sort(vec.begin(), vec.end(), cmp);
        // 같은 위치에 있으면 잡아먹기. (여러마리 존재 가능)
        for (int i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i].isDelete) continue;
            for (int j = i + 1; j < vec.size(); j++)
            {
                if (vec[i].r != vec[j].r) break;

                if (vec[j].isDelete) continue;
                if (vec[i].r == vec[j].r && vec[i].c == vec[j].c)
                {
                    if (vec[i].z > vec[j].z)
                        vec[j].isDelete = true;
                    else if (vec[i].z < vec[j].z)
                        vec[i].isDelete = true;
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Init();

    Slove();

    cout << counts << endl;
}
