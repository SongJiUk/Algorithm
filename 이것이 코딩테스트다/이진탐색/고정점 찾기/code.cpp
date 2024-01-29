
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;


int binary_search(int start, int end)
{
    if(start > end) return -1;

    int middle = (start+ end) /2;

    if(vec[middle] == middle) return middle;
    else if(vec[middle] > middle) return binary_search(start, middle-1);
    else return binary_search(middle+1, end);
}

int main(void) {
    int n;
    cin >> n;
    for(int i =0; i<n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    int result = binary_search(0,n-1);

    cout << result << endl;
}
