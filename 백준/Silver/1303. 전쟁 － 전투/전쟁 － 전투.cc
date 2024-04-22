#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
 
int N, M;
const int MAX = 101;
char input[MAX][MAX];
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { 0, };
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
int wSum = 0; //W병사 위력 합
int bSum = 0; //B병사 위력 합
int s = 1;    //뭉친 병사 수
queue<pair<int, int>> q;
 
void BFS(int y, int x) {
    visited[y][x] = true;
    q.push(make_pair(y, x));
 
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (ny < 0 || nx < 0 || ny >= M || nx >= N)
                continue;
            if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = true;
                s++;
                q.push(make_pair(ny, nx));
            }
        }
    }
}
 
void reset() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
            map[i][j] = 0;
        }
    }
}
 
 
int main() {
    cin >> N >> M;
 
    /*입력 받기*/
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1s", &input[i][j]);
        }
    }
 
    /*W=1, B=0로 변환하여 map에 저장*/
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (input[i][j] == 'W') {
                map[i][j] = 1;
            }
        }
    }
 
    /*W의 BFS*/
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                BFS(i, j);
                wSum += s * s;
                s = 1;
            }
        }
    }
 
    /*map, visited 초기화*/
    reset();
 
    /*B=1, W=0로 변환하여 map에 저장*/
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (input[i][j] == 'B') {
                map[i][j] = 1;
            }
        }
    }
 
    /*B의 BFS*/
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                BFS(i, j);
                bSum += s * s;
                s = 1;
            }
        }
    }
 
    cout << wSum << " " << bSum;
}
