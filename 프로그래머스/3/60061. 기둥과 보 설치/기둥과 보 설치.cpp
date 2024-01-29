#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

bool Check(vector<vector<int>> answer)
{
    for(int i =0; i<answer.size(); i++)
    {
        int x = answer[i][0];
        int y = answer[i][1];
        int a = answer[i][2];

        //기둥
        if(a == 0)
        {
            bool check = false;
            if(y == 0) check = true;

            for(int j = 0; j < answer.size(); j++)
            {
                //왼쪽 보
                if(x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                {
                    check = true;
                }

                //오른쪽 보
                if(x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                {
                    check = true;
                }

                //기둥
                if(x == answer[j][0] && y-1 == answer[j][1] && 0 == answer[j][2])
                {
                    check = true;
                }
            }

            if(!check) return false;
        }
        //보
        else if(a == 1)
        {
            bool check = false;
            bool left = false;
            bool right = false;


            for(int j = 0; j<answer.size(); j++)
            {
                if(x == answer[j][0] && y -1 == answer[j][1] && 0 == answer[j][2])
                {
                    check = true;
                }

                if(x +1 == answer[j][0] && y -1 == answer[j][1] && 0 == answer[j][2])
                {
                    check = true;
                }

                if(x -1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                {
                    left = true;
                }

                if(x+1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                {
                    right = true;
                }
            }

            if(left && right) check = true;
            if(!check) return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    //build_frame의 개수만큼 돌린다.
    for(int i =0; i<build_frame.size(); i++)
    {
        

        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        
        if(b == 0) //삭제
        {
            int index = 0;
            for(int j = 0; j<answer.size(); j++)
            {
                if(x == answer[j][0] && y == answer[j][1] && a == answer[j][2])
                {
                    index = j;
                }
            }

            vector<int> del = answer[index];
            answer.erase(answer.begin() + index);
            if(!Check(answer))
            {
                answer.push_back(del);
            }
        }
        else //설치
        {
            vector<int> result;
            result.push_back(x);
            result.push_back(y);
            result.push_back(a);
            answer.push_back(result);

            if(!Check(answer)) answer.pop_back();
        }

        
    }
    sort(answer.begin(), answer.end());
    return answer;
}
