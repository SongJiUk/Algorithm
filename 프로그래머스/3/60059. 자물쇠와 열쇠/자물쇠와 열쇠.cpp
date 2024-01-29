#include <bits/stdc++.h>


using namespace std;


vector<vector<int>> turn(vector<vector<int>> key)
{
    
    int M = key.size();
    vector<vector<int>> turn_key(M, vector<int>(M));
    for(int i = 0; i<M; i++)
    {
        for(int j = 0; j<M; j++)
        {   
            turn_key[j][M-i-1] = key[i][j];
            
        }
    }
    return turn_key;
}

bool Check(vector<vector<int>> lock)
{

    int size = lock.size() / 3 ;

    for(int i = size; i< size * 2; i++)
    {
        for(int j = size; j<size*2; j++)
        {
            if(lock[i][j] != 1) return false;
        }
    }
    return true;
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int M = key.size();
    int N = lock.size();
    
    vector<vector<int>> checklock( N * 3, vector<int>( N * 3));
    
    for(int i = 0; i<N; i++)
    {
        for (int j =0; j<N; j++)
        {
            checklock[i+N][j+N] = lock[i][j];
        }
    }
    
    
    for(int t = 0; t <4; t++)
    {
        key = turn(key);

        for(int x = 0; x < N * 2; x++)
        {
            for(int y = 0; y < N * 2; y++)
            {

                
                for(int i = 0; i < M; i++)
                {  
                    for(int j = 0; j< M; j++)
                    {

                        checklock[x+i][y+j] += key[i][j];
                    }

                }

                if(Check(checklock)) return true;

                for(int i = 0; i < M; i++)
                {  
                    for(int j = 0; j< M; j++)
                    {

                        checklock[x+i][y+j] -= key[i][j];
                    }

                }
            }
        }

 
    }
    return false;
}