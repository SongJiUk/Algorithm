
#include <iostream>
#include <queue>

using namespace std;

    
int main(void) {

    int N,x;
    vector<int> vec;
    cin >> N >> x;

    for(int i =0; i<N; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }    
    

    auto left = lower_bound(vec.begin(), vec.end(), x);
    auto right = upper_bound(vec.begin(), vec.end(), x);

    int sum = right - left;

    if(sum != 0) cout << sum << endl;
    else cout << "-1" << endl;
}
