#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    cin >> N;
    
    for(int i =0; i<N; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int result = 0;
    
    for(int i =0; i<N -1; i++)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();
        
        result += (a+b);
        pq.push(a+b);
    }

    cout << result << endl;
    return 0;
}